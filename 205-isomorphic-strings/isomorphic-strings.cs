public class Solution {
    public bool IsIsomorphic(string s, string t) {
        
            if (s.Length != t.Length) return false;
            int sHasDuplicates =  s.Distinct().Count();
            int tHasDuplicates =  t.Distinct().Count();
           
            if(sHasDuplicates > tHasDuplicates)
            {
                (t, s) = (s, t);
            }
            Dictionary<Char, Char> charDict = new();
            for(int i =0;i<s.Length;i++) {
                if (charDict.ContainsKey(s[i]) )
                {
                    if(charDict[s[i]] != t[i])
                        return false;
                }
                else
                {
                    charDict.Add(s[i], t[i]);
                }
            }
            return true;
    }
}