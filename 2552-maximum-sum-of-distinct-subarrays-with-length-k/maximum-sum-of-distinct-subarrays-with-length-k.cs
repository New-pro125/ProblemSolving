public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        long maxSum = 0, currentSum = 0;
        HashSet<int> windowSet = new HashSet<int>();
        int start = 0;

        for (int end = 0; end < nums.Length; end++) {
        
            while (windowSet.Contains(nums[end])) {
                windowSet.Remove(nums[start]);
                currentSum -= nums[start];
                start++;
            }

        
            windowSet.Add(nums[end]);
            currentSum += nums[end];

        
            if (end - start + 1 == k) {
                maxSum = Math.Max(maxSum, currentSum);

            
                windowSet.Remove(nums[start]);
                currentSum -= nums[start];
                start++;
            }
        }

        return maxSum;
    }
}
