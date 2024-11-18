public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int[] cumulativeXor = new int[nums.Length],queryK = new int[nums.Length];
        int maxNumber = (int)Math.Pow(2,maximumBit)-1; 
        for(int i =0;i<nums.Length;i++){
            cumulativeXor[i] = nums[i] ^ (i>0 ? cumulativeXor[i-1] : 0);
        }
        for(int i =nums.Length-1;i>=0;i--){
            // Console.WriteLine(cumulativeXor[i]);
            queryK[nums.Length-1-i] = maxNumber ^ cumulativeXor[i];
        }
        return queryK;
    }
}