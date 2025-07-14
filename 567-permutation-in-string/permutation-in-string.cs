public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if(s1.Length > s2.Length) return false;
        Span<int> s1Count = stackalloc int[26];
        Span<int> s2Count = stackalloc int[26];
        for(int i= 0;i<s1.Length;i++){
            s1Count[s1[i] - 'a']++;
        }
        for(int i =0;i<s2.Length;i++){
            s2Count[s2[i] - 'a']++;
            if(i >= s1.Length){
                s2Count[s2[i - s1.Length] -'a']--;
            }
            if(s1Count.SequenceEqual(s2Count)) return true;
        }
        return false;
    }
}