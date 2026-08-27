class Solution {
    public String lexGreaterPermutation(String s, String target) {
    int n = s.length();
      int[] freq = new int[26];
      for (char ch : s.toCharArray()) {
        freq[ch - 'a']++;
      }
      int matched = 0;
      while (matched < n && freq[target.charAt(matched) - 'a'] > 0) {
        freq[target.charAt(matched) - 'a']--;
        matched++;
      }
      for (int pos = Math.min(matched, n - 1); pos >= 0; pos--) {
        if (pos < matched) {
          freq[target.charAt(pos) - 'a']++;
        }
        int targetChar = target.charAt(pos) - 'a';
        for (int c = targetChar + 1; c < 26; c++) {
          if (freq[c] > 0) {
            freq[c]--;
            StringBuilder result = new StringBuilder(n);
            result.append(target, 0, pos);
            result.append((char) ('a' + c));
            for (int x = 0; x < 26; x++) {
              while (freq[x]-- > 0) {
                result.append((char) ('a' + x));
              }
            }
            return result.toString();
          }
        }
      }
      return "";

    }
}