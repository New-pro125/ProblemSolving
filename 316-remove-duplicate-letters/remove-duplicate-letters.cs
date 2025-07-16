public class Solution {
    public string RemoveDuplicateLetters(string s) {
         int n = s.Length;
 Span<int> freq = stackalloc int[26];
 BitArray inStack = new BitArray(26);
 Stack<char> temp = new();
 for (int i = 0; i < n; i++)
 {
     freq[s[i] - 'a'] = i;

 }
 for(int i = 0; i < n; i++)
 {
     if(inStack[s[i]-'a']) continue;
     
     while (temp.Count > 0 && temp.Peek() > s[i] && freq[temp.Peek() - 'a'] > i)
     { 
         inStack[temp.Pop() - 'a'] = false;
     }
     
         temp.Push(s[i]);
         inStack[s[i] - 'a'] = true;
     
 }
 return new string(temp.Reverse().ToArray());
    }
}