public class Solution {
    private int LengthOfLISHelper(IReadOnlyList<int> nums,int idx,int prevIdx,int?[,] memo)
    {
        if(idx == nums.Count)
        {   
            return 0;
        }
        if (memo[prevIdx + 1 , idx] != null)
        {
            return memo[prevIdx + 1 , idx].Value;
        }
        int ans = 0;

    // take  this number
        if(prevIdx == -1 || nums[prevIdx] < nums[idx])
            ans = Math.Max(ans , (1 + LengthOfLISHelper(nums, idx + 1, idx,memo)));
    // leave this number
        ans = Math.Max(ans, (LengthOfLISHelper(nums,idx + 1, prevIdx, memo)));
        memo[prevIdx + 1, idx] = ans;
        return ans;
    }
    public int LengthOfLIS(int[] nums) {
        int n = nums.Length;
        int?[,] memo = new int?[n + 1, n];
        return LengthOfLISHelper(nums,0,-1,memo);
    }
}