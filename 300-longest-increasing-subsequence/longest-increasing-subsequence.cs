public class Solution {
    public int LengthOfLIS(int[] nums) {
        int n = nums.Length;
        int[,] memo = new int[n + 1, n+1];
        for(int idx = n - 1; idx >= 0; idx--)
            {
                for(int prevIdx = idx-1;prevIdx >= -1; prevIdx--)
                    {
                        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
                            memo[prevIdx + 1, idx] = Math.Max(memo[prevIdx + 1, idx], 1 + memo[idx + 1, idx + 1]);
                        memo[prevIdx + 1, idx] = Math.Max(memo[prevIdx + 1, idx], memo[prevIdx + 1, idx + 1]);
                    }
            }
              
        return memo[0,0];
    }
}