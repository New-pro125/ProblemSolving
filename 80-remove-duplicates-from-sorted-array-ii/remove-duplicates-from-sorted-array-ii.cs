public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int[] freq = new int [20001]; // The Freq of Numbers (Normalize to be from 0 to 201)
        for(int i =0 ;i<nums.Length;i++){
            freq[nums[i]+10000]++;
        }
        int numsIdx=0;
        for(int i=0;i<freq.Length;i++){
           if(freq[i]>=2){
                nums[numsIdx] = i-10000;
                nums[numsIdx+1] = nums[numsIdx]; 
                numsIdx+=2;
            }
            else if(freq[i]>0){
                nums[numsIdx] = i-10000; 
                numsIdx+=1;
            }
        }
        return numsIdx;
    }
}