public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
       int n = nums.Length;
    if (n == 0 || k == 0) return Array.Empty<int>();

    int[] result = new int[n - k + 1];
    Span<int> deque = stackalloc int[n]; // holds indices
    int front = 0, back = 0;

    for (int right = 0; right < n; right++)
    {
        // Remove elements smaller than current from the back
        while (back > front && nums[deque[back - 1]] < nums[right])
            back--;

        deque[back++] = right;

        // Remove front if it's outside the window
        if (deque[front] <= right - k)
            front++;

        // Add to result if window has formed
        if (right >= k - 1)
            result[right - k + 1] = nums[deque[front]];
    }

    return result;
    }
}