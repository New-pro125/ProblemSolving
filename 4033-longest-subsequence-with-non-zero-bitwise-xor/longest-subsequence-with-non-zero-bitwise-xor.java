class Solution {
    public int longestSubsequence(int[] nums) {
        int i = 0, j = 0;
        int length = 0;
        int xorResult = 0;
        Arrays.sort(nums);
        while(j < nums.length){
            xorResult ^= nums[j];
            // System.out.println(i + " " + j  + ", XorResult: " + xorResult);
            while(i <= j && xorResult == 0 && j == nums.length - 1){
                // System.out.println("XorResult is zero , j:" + j );
                xorResult ^= nums[i];
                i++;
            }
            j++;
            if(xorResult != 0)
                length = Math.max(length, j - i);
        }      
        return length;
    }
}
// 