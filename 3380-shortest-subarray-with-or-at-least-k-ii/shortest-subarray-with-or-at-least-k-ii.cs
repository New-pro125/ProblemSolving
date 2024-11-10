public class Solution {
    private int ConvertBitsCountsToNumber(int[] bitCounts){
        int number =0 ;
        for(int pos = 0;pos<=bitCounts.Length-1;pos++){
            if(bitCounts[pos]!=0){
                number |=1<<pos;
            }
        }
        return number;
    }
    private void UpdateBitCounts(int[] bitCounts,int number,int delta){
        for(int pos=0;pos<bitCounts.Length;pos++){
            if(((number >> pos) & 1 ) !=0){
                bitCounts[pos]+=delta;
            }
        }
    }
    private bool HasValidSubarray(int[]nums,int targetSum,int windowSize){
        int[] bitsCount = new int[32];
        for(int i = 0;i<nums.Length;i++){
            UpdateBitCounts(bitsCount,nums[i],1);
            if(i>=windowSize){
                UpdateBitCounts(bitsCount,nums[i-windowSize],-1);
            }
            if(i>=windowSize-1 && ConvertBitsCountsToNumber(bitsCount) >=targetSum)
                return true;
        }
        return false;
    }
    public int MinimumSubarrayLength(int[] nums, int k) {
        int minLength = int.MaxValue;
        int windowStart =0 ,windowEnd = 0 ;
        int [] bitCounts = new int[32];
        while(windowEnd <nums.Length){
            UpdateBitCounts(bitCounts,nums[windowEnd],1);
            while(windowStart <=windowEnd && ConvertBitsCountsToNumber(bitCounts)>=k){
                minLength = Math.Min(minLength,windowEnd - windowStart +1);
                UpdateBitCounts(bitCounts,nums[windowStart],-1);
                windowStart++;
            }
            windowEnd++;
        }
        return minLength == int.MaxValue ? -1 : minLength;
    }
}