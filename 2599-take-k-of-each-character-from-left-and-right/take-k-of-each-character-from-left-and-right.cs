public class Solution {
    public int TakeCharacters(string s, int k) {
        int n = s.Length;
    
        int[] count = new int[3];
        foreach (char c in s) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }
        int[] window = new int[3];
        int left = 0, maxWindow = 0;
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;

            while (left <= right &&
                   (count[0] - window[0] < k || count[1] - window[1] < k ||
                    count[2] - window[2] < k)) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = Math.Max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
}
