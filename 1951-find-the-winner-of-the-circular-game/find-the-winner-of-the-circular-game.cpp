class Solution {
public:
    int findTheWinner(int n, int k) {        
        vector<int>vis(n);
        int visN = 0 ;
        int start = 0;
        int remove = 0;
        while(visN!=n-1){
            int t = k-1;
            while(t){
                if(!vis[start]) 
                    t--;
                start = (start+1)%n;
            }
            while(vis[start]) start = (start+1)%n;
            vis[start]=1;
            visN++;
            start = (start+1)%n;
            while(vis[start]) start=(start+1)%n;
        }   
        return start+1;
    }
};