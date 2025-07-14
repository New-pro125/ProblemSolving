public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
         int[] arr = new int[26];
 foreach (char c in magazine)
 {
     arr[c - 'a']++;
 }
 foreach (char c in ransomNote)
 {
     if (arr[c - 'a'] <= 0) return false;
     arr[c - 'a']--;
 }
 return true;
    }
}