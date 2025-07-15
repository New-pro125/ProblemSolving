public class Solution {
    public int LongestValidParentheses(string s) {
    int n = s.Length, maxLength = 0;
Stack<int> temp = new();
temp.Push(-1);
for(int i = 0; i < n; i++)
{
    if (s[i].Equals('('))
    {
        temp.Push(i);
        
    }
    else
    {
        temp.Pop();
        if(temp.Count == 0)
        {
            temp.Push(i);
        }
        int top = temp.Peek();
        maxLength = Math.Max(maxLength, i - top);
    }
}
return maxLength;}
}