public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int[] freq = new int [201]; // The Freq of Numbers (Normalize to be from 0 to 201)
        for(int i =0 ;i<nums.Length;i++){
            freq[nums[i]+100]++;
        }
        int numsIdx=0;
        for(int i=0;i<freq.Length;i++){
           if(freq[i]!=0){
                nums[numsIdx] = i-100;
                numsIdx++;
            }
        }
        return numsIdx;
    }
}