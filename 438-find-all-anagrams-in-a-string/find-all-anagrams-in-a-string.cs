public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        if(s.Length < p.Length) return [];
        int[] pCount = new int[26];
        int[] sCount = new int[26];
        foreach(char c in p){
            pCount[c-'a']++;
        }
        List<int> result = new();
        for(int i =0;i<s.Length;i++){
            sCount[s[i] - 'a']++;
            if(i >= p.Length){
                sCount[s[i-p.Length] - 'a']--;
            }
            if(sCount.SequenceEqual(pCount)) result.Add(i - p.Length + 1);
        }
        return result;
    }
}