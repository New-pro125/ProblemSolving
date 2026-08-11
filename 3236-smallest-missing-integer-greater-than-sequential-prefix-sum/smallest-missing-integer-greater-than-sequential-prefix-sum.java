
class Solution {
    public int missingInteger(int[] nums) {
        int i = 1,sum = nums[i-1];
        while( i < nums.length && nums[i] == nums[i-1] + 1) {
            sum +=nums[i];
            i++;
        }
        if(i == 1 && nums.length == 1) {
            return sum + 1;
        }
        boolean exists = i == 1;
        sum += exists ? 1 : 0;
        Arrays.sort(nums, i, nums.length);
        for(int j = i; j< nums.length;j++){
            if(sum == nums[j]){ 
                sum = nums[j] + 1;
                
            };
        }
        return sum;
    }
}