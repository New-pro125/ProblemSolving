public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
        long[] prefixNums = new long[nums.Length];
        for(int k=0;k<nums.Length;k++){
            prefixNums[k] = nums[k] + ((k>0)? prefixNums[k-1] : 0);
        }
        int j = 0,i =0,length = int.MaxValue;
        while(i<prefixNums.Length && j<prefixNums.Length){
            if(target > (prefixNums[i] - ((j>0) ? prefixNums[j-1] : 0))) {
                i++;
            }
            else {
                length = Math.Min(length,i-j+1);
                j++;
            }
        }
        return length==int.MaxValue? 0 : length;
    }
}