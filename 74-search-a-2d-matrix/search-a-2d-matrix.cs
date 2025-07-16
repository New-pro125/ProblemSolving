public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        return matrix.SelectMany(x => x).ToList().BinarySearch(target) >= 0;  
    }
}