class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>dp(m);
     
        for(int i = m-1;i>=0;i--){
             vector<int>curr_dp(m,1e9);
            for(int j = 0;j<i+1;j++){
                    {
                        curr_dp[j] = min(curr_dp[j],dp[j]+triangle[i][j]);
                    if(j+1<m)
                    curr_dp[j] = min(curr_dp[j],dp[j+1]+triangle[i][j]);}
            }
            dp=curr_dp;
        }
       
         return dp[0];

       
    }
};