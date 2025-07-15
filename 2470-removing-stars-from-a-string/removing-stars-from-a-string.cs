public class Solution {
    public string RemoveStars(string s) {
        Stack<char> res = new();
 foreach(char c in s)
 {
     if(c.Equals('*'))
     {
         if (res.Count > 0)
             res.Pop();
     }
     else
     {
         res.Push(c);
     }
 }
 return new string(res.Reverse().ToArray());
    }
}