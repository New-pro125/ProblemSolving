class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] freq = new int[51];
        boolean [] freq_in_subarr = new boolean [51];
        int n = nums.length;
        for(int j = 0; j< n - k + 1; j++){
            for(int i = 0; i< k; i++){
                if(freq_in_subarr[nums[j + i]] == false)
                    freq[nums[j + i]]++;
                freq_in_subarr[nums[j + i]] = true;
            }
            Arrays.fill(freq_in_subarr,false);
        }
        int max_value = -1;
        for(int i = 0;i<51;i++){
            if(freq[i] == 1)
                max_value = Math.max(max_value, i);
        }
        return max_value;
    }
}