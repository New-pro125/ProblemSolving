public class Solution {
    public int FirstMissingPositive(int[] nums) {
         int n = nums.Length;
           int i = 0;
  while(i < n)
  {
      var correctIdx = nums[i] - 1;
      if (nums[i] > 0 && nums[i]<=n && nums[i] != nums[correctIdx])
      {
          (nums[i], nums[correctIdx]) = (nums[correctIdx], nums[i]);
      }
      else
      {
          i++;
      }
  }
  for(i = 0; i < n; i++)
  {
      if (nums[i] != i + 1)
      {
          return i + 1;
      }
  }
  return n + 1;
    }
}