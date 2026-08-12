class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
       Map<Integer,Integer> freq = new HashMap<>();
       int i = 0, j = 0;
       int maxLength = 0;
       while(i< nums.length && j < nums.length){
            freq.put(nums[j],freq.getOrDefault(nums[j],0) + 1);
            while(i < j && freq.get(nums[j]) > k){
                    freq.put(nums[i],freq.getOrDefault(nums[i],0) - 1);
                    i++;
            }
            j++;
            maxLength = Math.max(maxLength, j - i);
       }
       return maxLength;
    }

}
// [4,4,4,4,4, 1,2,3,4,5,6], k = 3