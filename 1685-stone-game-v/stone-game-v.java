class Solution {
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        int[] presum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            presum[i + 1] = stoneValue[i] + presum[i];
        }
        int[][] dp = new int[n][n];
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    int leftSum = presum[k + 1] - presum[i];
                    int rightSum = presum[j + 1] - presum[k + 1];
                    if (leftSum < rightSum) {
                        dp[i][j] = Math.max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = Math.max(dp[i][j], rightSum + dp[k + 1][j]);
                    } else {
                        dp[i][j] = Math.max(dp[i][j], Math.max(leftSum + dp[i][k],rightSum + dp[k + 1][j]));
                    }
                }
            }
        }
        return dp[0][n - 1];

    }
}