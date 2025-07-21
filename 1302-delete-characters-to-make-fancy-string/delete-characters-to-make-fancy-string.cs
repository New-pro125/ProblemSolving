public class Solution {
    public string MakeFancyString(string s) {
        int n = s.Length;
   StringBuilder resultString = new();
   for (int i = 0; i < n; i++)
   {
       if (resultString.Length >= 2)
       {
           if (!s[i].Equals(resultString[resultString.Length - 1]) ||
               (s[i].Equals(resultString[resultString.Length -1]) && !resultString[resultString.Length - 1].Equals(resultString[resultString.Length - 2])))
           {
               resultString.Append(s[i]);
           }
       }
       else
       {
           resultString.Append(s[i]);
       }
   }
   return resultString.ToString();
    }
}