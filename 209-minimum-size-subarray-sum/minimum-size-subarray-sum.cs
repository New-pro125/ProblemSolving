public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
  int left = 0, right = 0, sumOfWindow = 0, minLength = int.MaxValue;
 for(right =0;right < nums.Length; right++)
 {
     sumOfWindow += nums[right];
     while(sumOfWindow >= target)
     {
         minLength = Math.Min(minLength, right - left + 1);
         sumOfWindow -= nums[left];
         left++;
     }
 }
 return minLength == int.MaxValue ? 0 : minLength;
    }
}