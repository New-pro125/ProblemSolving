public class Solution {
    public void MoveZeroes(int[] nums) {
        int cntZeros = 0,lastNonZeroIdx= 0;
        for(int i=0 ;i<nums.Length;i++){
            if(nums[i]==0){
                cntZeros++;
            }
            else {
                lastNonZeroIdx = i-cntZeros;
                nums[lastNonZeroIdx] = nums[i]; 
            }
        }
        for(int i = lastNonZeroIdx+1;i<nums.Length;i++){
            nums[i] = 0;
        }
    }
}