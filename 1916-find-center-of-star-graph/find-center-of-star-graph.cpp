class Solution {
private:
vector<int>visited;    
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        visited.resize(n+1);
        for(auto i:edges){
            visited[i[0]]++;
            visited[i[1]]++;
        }
        return max_element(visited.begin(),visited.end())-visited.begin();
    }
};