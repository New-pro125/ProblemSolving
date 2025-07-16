public class Solution {
    public int LengthOfLIS(int[] nums) {
        List<int> piles = new();
        foreach (int num in nums)
        {
            int idx = piles.BinarySearch(num);
            if (idx < 0) idx = ~idx;
            if (idx == piles.Count)
            {
                piles.Add(num);
            }
            else
            {
                piles[idx] = num;
            }
        }
        return piles.Count;
    }
}