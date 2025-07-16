public class Solution {
    public int LargestRectangleArea(int[] heights) {
         int area = 0;
 Stack<Tuple<int, int>> temp = new();
 for (int start = 0; start < heights.Length; start++)
 {
     int nextStart = start;
     while (temp.Count > 0 && heights[start] < temp.Peek().Item1)
     {
         Tuple<int, int> window = temp.Pop();
         int width = start - window.Item2;
         area = Math.Max(area, window.Item1 * width);
         nextStart = window.Item2;
     }
     temp.Push(new Tuple<int, int>(heights[start], nextStart));
 }
 while (temp.Count > 0)
 {
     Tuple<int, int> window = temp.Pop();
     int width = heights.Length - window.Item2;
     area = Math.Max(area, window.Item1 * width);
 }
 return area;
    }
}