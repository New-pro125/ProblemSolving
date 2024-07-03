class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp(n);

        for(int i = n-1;i>=0;i--){
             vector<int>curr_dp(n,1e9);
            for(int j = n-1;j>=0;j--){
                curr_dp[j] = min(curr_dp[j],dp[j]+matrix[i][j]);
                if(j+1<n)
                    curr_dp[j] = min(curr_dp[j],dp[j+1]+matrix[i][j]);
                if(j-1>=0)
                    curr_dp[j] = min(curr_dp[j],dp[j-1]+matrix[i][j]);
            }
            dp=curr_dp;
        }
       
         return *min_element(dp.begin(),dp.end());
    }
};