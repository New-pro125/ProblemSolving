public class Solution {
    public char[][] RotateTheBox(char[][] box) {
        int m = box.Length;       // Number of rows
        int n = box[0].Length;    // Number of columns
        
        // Step 1: Apply gravity row by row in the original box
        for (int i = 0; i < m; i++) {
            int emptyIndex = n - 1; // Start from the rightmost position
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    // Move stone down to the first empty spot
                    box[i][j] = '.';
                    box[i][emptyIndex] = '#';
                    emptyIndex--; // Update the empty position
                } else if (box[i][j] == '*') {
                    // Reset the empty index to the position before the obstacle
                    emptyIndex = j - 1;
                }
            }
        }

        // Step 2: Rotate the box 90 degrees clockwise
        char[][] rotatedBox = new char[n][];
        for (int i = 0; i < n; i++) {
            rotatedBox[i] = new char[m];
            for (int j = 0; j < m; j++) {
                rotatedBox[i][j] = box[m - j - 1][i];
            }
        }

        return rotatedBox;
    }
}
