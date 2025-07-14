public class Solution {
    public int NumSplits(string s) {
        int res = 0, leftUnique = 0, rightUnique = 0;
Span<int> left = stackalloc int[26] , right = stackalloc int[26];
foreach (char c in s)
{
    if (++right[c-'a'] == 1)
    {
        ++rightUnique;
    }
}
foreach(char c in s)
{
    if (++left[c - 'a'] == 1)
    {
        ++leftUnique;
    }
    if (--right[c-'a'] == 0)
    {
        --rightUnique;
    }
    if (leftUnique > rightUnique) return res;
    if (leftUnique == rightUnique) res++;
}
return res;
    }
}