class Solution {
    public int missingMultiple(int[] nums, int k) {
        for(int i = 1;i<101;i++){
            int multiple = i * k;
            boolean found = false;
            for(int j = 0;j<nums.length;j++){
                found |= multiple == nums[j];
            }
            if(!found) {
                return multiple;
            }
        }
        return 101 * k;
        
    }
}