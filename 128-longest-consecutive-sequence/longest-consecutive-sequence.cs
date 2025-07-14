public class Solution {
    public int LongestConsecutive(int[] nums) {
    if(nums.Length == 0) return 0;
    Array.Sort(nums);
int res = 1;
int seq = 1;
for (int i = 0; i < nums.Length - 1; i++)
{
    if (nums[i] == nums[i + 1] - 1)
    {
        seq++;
    }
    else if (nums[i] == nums[i + 1]) continue;
    else
    {
        res = Math.Max(res, seq);
        seq = 1;
    }
}
res = Math.Max(res, seq);
return res; 
    }
}