public class Solution {
    public string RemoveDuplicateLetters(string s) {
    int n = s.Length;
    int[] lastIndex = new int[26];
    bool[] used = new bool[26];
    Stack<char> stack = new Stack<char>();

     for (int i = 0; i < n; i++){

         lastIndex[s[i] - 'a'] = i; 
     }

    for(int i = 0;i < n;i++){
       char c = s[i];

      if(used[c-'a'])  continue;
        
      while(stack.Count > 0 && stack.Peek() > c && lastIndex[stack.Peek() - 'a'] > i){

        char removed = stack.Pop();
        used[removed - 'a'] = false;
      }
      stack.Push(c);
      used[c - 'a'] = true;
   }

  char[] result = stack.Reverse().ToArray(); 
  return new string(result);

    }
}