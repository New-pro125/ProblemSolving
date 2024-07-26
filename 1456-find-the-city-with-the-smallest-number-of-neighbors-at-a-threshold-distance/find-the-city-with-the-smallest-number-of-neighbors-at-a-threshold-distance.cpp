class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>>dist(n,vector<int>(n,INT32_MAX));
            for(int i=0;i<n;++i){
                dist[i][i]=0;
            }
            for(const auto &edge:edges){
                int u = edge[0],v=edge[1],d=edge[2];
                dist[u][v] = d;
                dist[v][u] = d;
            }
            //Floyd-Warshall Algorithm
            for(int w = 0;w<n;++w){
                for(int u =0;u<n;++u){
                    for(int v =0;v<n;++v){
                        if(dist[u][w]!=INT32_MAX&&dist[w][v]!=INT32_MAX){
                            dist[u][v] = min(dist[u][v],dist[u][w]+dist[w][v]);
                        }
                    }
                }
            }
            int minReachableCities =INT32_MAX;
            int bestCity = 0;
            for(int i =0;i<n;i++){
                int reachableCities =0;
                for(int j =0;j<n;++j){
                    if(dist[i][j]<=distanceThreshold){
                        reachableCities++;
                    }
                }
                if(reachableCities<=minReachableCities){
                    minReachableCities = reachableCities;
                    bestCity = i;
                }
            }
        return bestCity;
    }
};