public class Solution {
    public string MinWindow(string s, string t) {
        if (t.Length > s.Length) return "";
Span<int> commonFreq = stackalloc int[256];
int left = 0, right = 0, startIdx = -1, windowLength = 0, minLength = int.MaxValue;
foreach (char c in t)
{
    commonFreq[c]++;
}
for( ;right < s.Length;right++)
{
    if (commonFreq[s[right]] > 0)
    {
        windowLength++;
    }
    commonFreq[s[right]]--;
    while(windowLength == t.Length)
    {
        if(right-left+1 < minLength)
        {
            minLength = right - left + 1;
            startIdx = left;
        }
        commonFreq[s[left]]++;
        if (commonFreq[s[left]] > 0)
            windowLength--;
        left++;
    }
}
return startIdx == -1 ? "" : s.Substring(startIdx, minLength);
    }
}