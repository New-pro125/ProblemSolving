public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        Span<int> letters = stackalloc int[26];
foreach (char c in magazine)
{
    letters[c - 'a']++;
}
foreach (char c in ransomNote)
{
    if (letters[c - 'a'] <= 0) return false;
    letters[c - 'a']--;
}
return true;
}
}