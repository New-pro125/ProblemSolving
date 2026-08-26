class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
      String result = null;
      int freq_1 = 0;
      int i = 0;
      int j = 0;
      while (j < s.length()) {
        freq_1 += s.charAt(j) == '1' ? 1 : 0;
        while (i <= j && (freq_1 > k|| (freq_1 == k && s.charAt(i) == '0'))) {
          freq_1 -= s.charAt(i) == '1' ? 1 : 0;
          i++;
        }
        if (freq_1 == k) {
          String curr_str = s.substring(i, j + 1);
         if (result == null || curr_str.length() < result.length()
                        || (curr_str.length() == result.length() && curr_str.compareTo(result) < 0)) {
                result = curr_str;
            }

        }
        j++;
      }
      return result == null ? "" : result;
    }
}