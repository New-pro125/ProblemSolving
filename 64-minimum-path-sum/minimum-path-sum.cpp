class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,1e9));
        // function<int(int,int)> cnt_ways=[&](int i,int j){
        //     if(i>=m||j>=n) return (int)1e7;
        //     if(i==m-1&&j==n-1) return grid[i][j];
        //     int& ans = dp[i][j];
        //     if(ans!=1e9) return ans;
        //     ans = min(ans,cnt_ways(i+1,j)+grid[i][j]);
        //     ans = min(ans,cnt_ways(i,j+1)+grid[i][j]);
        //     return ans;
        // };
        // return cnt_ways(0,0);
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i+1<m)
                    dp[i][j] = min(dp[i][j],dp[i+1][j]+grid[i][j]);
                if(j+1<n)
                    dp[i][j] = min(dp[i][j],dp[i][j+1]+grid[i][j]);
            }
        }
       
        return dp[0][0];
    }
};