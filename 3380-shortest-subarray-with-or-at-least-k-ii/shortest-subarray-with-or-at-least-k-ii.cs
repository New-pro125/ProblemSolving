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
        int start= 1,end = nums.Length,minLength=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(HasValidSubarray(nums,k,mid)){
                minLength = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return minLength;
    }
}