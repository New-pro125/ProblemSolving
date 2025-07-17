public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        for (int i = 0; i < n; i++) {         
            for (int j = i; j < n; j++) {     
                (matrix[i][j],matrix[j][i]) = (matrix[j][i],matrix[i][j]);           
            }
        }
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < n/2; j++) {     
                (matrix[i][j],matrix[i][n-j-1]) = (matrix[i][n-j-1],matrix[i][j]);           
            }
        }
    }
}