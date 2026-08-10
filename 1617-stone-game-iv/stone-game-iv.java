class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n+1];
        // for(int i = 1;i<n+1;i++) dp[i] = true;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i * i <= j; i++) {
                if (!dp[j - i * i]) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}