public class Solution {
    public int[] ResultsArray(int[] nums, int k) {
        int n = nums.Length;
        if (n == 1) {
            return new int[] { nums[0] };
        }
        if (k == 1) {
            return nums;
        }
        int[] powers = new int[n - k + 1];

        for (int i = 0; i <= n - k; i++) {
            bool isSorted = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] - nums[j] != 1) {
                    isSorted = false;
                    break;
                }
            }

            powers[i] = isSorted ? nums[i + k - 1] : -1;
        }

        return powers;
    }
}
