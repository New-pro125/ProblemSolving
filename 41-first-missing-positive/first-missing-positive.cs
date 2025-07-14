public class Solution {
    public int FirstMissingPositive(int[] nums) {
         int n = nums.Length;
         bool contains1 = false;
         for(int i =0;i<n;i++){
            if(nums[i] ==1){
                contains1 = true;
            }
            else if(nums[i] <=0 || nums[i] > n)
                nums[i] =1;
         }
         if(!contains1) return 1;
         for(var i = 0;i<nums.Length;i++){
            var value = Math.Abs(nums[i]);
            if(value == n){
                nums[0] = -Math.Abs(nums[0]);
            }
            else {
                nums[value] = - Math.Abs(nums[value]);
            }
         }
         for(var i = 1;i<n;i++){
            if(nums[i] > 0) return i;
         }
         if(nums[0] > 0) return n;
         return n+1;
    }
}