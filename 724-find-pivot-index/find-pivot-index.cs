public class Solution {
    public int PivotIndex(int[] nums) {
        int[] prefixSum = new int[nums.Length];
        for(int i=0;i<nums.Length;i++){
            prefixSum[i] = nums[i] + ((i>0) ? prefixSum[i-1] : 0);
            Console.Write(prefixSum[i]);
            Console.Write(" ");
        }

        for(int i=0;i<nums.Length;i++){
            if((prefixSum[nums.Length-1]-prefixSum[i]) == ((i>0) ? prefixSum[i-1] : 0))
                return i;
        }
        return -1;
    }
}