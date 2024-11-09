public class Solution {
    public int[] SortedSquares(int[] nums) {
        List<int> squaredNums = new List<int>();
        foreach(int number in nums){
            squaredNums.Add(number*number);
        }
        squaredNums.Sort();
        return squaredNums.ToArray();
    }
}