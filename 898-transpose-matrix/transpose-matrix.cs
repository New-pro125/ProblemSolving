public class Solution {
    public int[][] Transpose(int[][] matrix) {
        int colLength = matrix.Length;
        int rowLength = matrix[0].Length;
        int[][] res = new int[rowLength][];
        for (int i = 0; i < rowLength; i++)
        {
            res[i] = new int[colLength];
        }
        for(int i = 0;i<colLength;i++){
            for(int j = 0 ;j<rowLength;j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
}