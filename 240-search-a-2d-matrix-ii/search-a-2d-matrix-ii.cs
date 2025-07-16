public class Solution {
    
    public bool SearchMatrix(int[][] matrix, int target) {
        int rows = matrix.Length,cols = matrix[0].Length,row = 0,col = cols -1;
        while(row < rows && col >=0){
            int current = matrix[row][col];
            if(current == target) return true;
            else if(target < current) col--;
            else row++;
        }
        return false;
    }
}