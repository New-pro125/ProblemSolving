class Solution {
    public boolean sumGame(String num) {
      int s1 = 0;
      int s2 = 0;
      int q1 = 0;
      int q2 = 0;
      for (int i = 0; i < num.length(); i++) {
        if (i < num.length() / 2) {
          if (num.charAt(i) == '?')
            q1++;
          else
            s1 += num.charAt(i) - '0';
        } else {
          if (num.charAt(i) == '?')
            q2++;
          else
            s2 += num.charAt(i) - '0';

        }
      }
      return (q1 + q2) % 2 == 1 || (s1 - s2 != (q2 - q1) / 2 * 9);
    }
}