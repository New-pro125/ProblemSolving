class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m);
        for(int i = 0;i<m;i++){
            dp[i] = vector<int>(i+1,1e9);
        }
        // for(int i=0;i<m;i++){
        //     dp[m-1][i]=triangle[m-1][i];
        // }
        // for(int i = m-1;i>=0;i--){
        //     for(int j = 0;j<i+1;j++){
        //         if(i+1<m)
        //             dp[i][j] = min(dp[i][j],dp[i+1][j]+triangle[i][j]);
        //     }
        // }
        function<int(int,int)> cnt_ways = [&](int i,int j ){
            if(i>=m || j>=m) return (int) 1e7;
            if(i==m-1) return triangle[i][j];
            int& ans = dp[i][j] ;
            if(ans!=1e9) return ans;
            ans = min(ans,cnt_ways(i+1,j)+triangle[i][j]);
            ans = min(ans,cnt_ways(i+1,j+1)+triangle[i][j]);
            return ans;
        };
        // for(int i = 0;i<m;i++){
        //     for(int j =0;j<i+1;j++)
        //         cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        // return dp[0][0];

        return cnt_ways(0,0);
    }
};