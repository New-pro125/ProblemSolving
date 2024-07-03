class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        if(obstacleGrid[m-1][n-1]==0)
        dp[m-1][n-1]=1;
    for(int i = m-1;i>=0;i--){
        for(int j =n-1;j>=0;j--){
            if(i+1<=m-1&&obstacleGrid[i][j]==0){
                dp[i][j] = (dp[i][j]+dp[i+1][j]);
            }
            if(j+1<=n-1&&obstacleGrid[i][j]==0){
                dp[i][j] = (dp[i][j]+dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
    }
};