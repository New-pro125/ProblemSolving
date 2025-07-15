public class Solution {
    public int MaxSubArray(int[] nums) {
          int currMax = 0, maxTillNow = int.MinValue;
  foreach (int num in nums) {
      currMax = Math.Max(currMax + num, num);
      maxTillNow = Math.Max(currMax, maxTillNow);
  }
  return maxTillNow;
    }
}