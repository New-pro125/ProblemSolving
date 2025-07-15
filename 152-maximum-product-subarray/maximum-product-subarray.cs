public class Solution {
    public int MaxProduct(int[] nums) {
        int Lproduct = 1;
        int Rproduct = 1;
        int max = nums[0];

        // Left to Right Pass
        for (int i = 0; i < nums.Length; i++) {
            Rproduct *= nums[i];
            max = Math.Max(max, Rproduct);
            if (Rproduct == 0) {
                Rproduct = 1;
            }
        }

        // Right to Left Pass
        for (int i = nums.Length - 1; i >= 0; i--) {
            Lproduct *= nums[i];
            max = Math.Max(max, Lproduct);
            if (Lproduct == 0) {
                Lproduct = 1;
            }
        }

        return max;
    }

}