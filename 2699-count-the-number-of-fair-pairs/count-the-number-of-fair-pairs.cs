public class Solution {
    private long LowerBound(int[] nums,int low,int high,int element){
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]>=element){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        long ans =0;
        for(int i=0;i<nums.Length;i++){
            long low = LowerBound(nums,i+1,nums.Length-1,lower-nums[i]); // Count the number of possible Numbers Not Taken
            long high = LowerBound(nums,i+1,nums.Length-1,upper-nums[i]+1);
            ans +=high-low;
        }
        return ans;
    }
}