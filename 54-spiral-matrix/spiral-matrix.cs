public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        List<int> result = new List<int>();
        if (matrix.Length == 0 || matrix[0].Length == 0)
            return result;

        int top = 0;
        int bottom = matrix.Length - 1;
        int left = 0;
        int right = matrix[0].Length - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse top row
            for (int i = left; i <= right; i++)
                result.Add(matrix[top][i]);
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++)
                result.Add(matrix[i][right]);
            right--;

            // Traverse bottom row if still within vertical bounds
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    result.Add(matrix[bottom][i]);
                bottom--;
            }

            // Traverse left column if still within horizontal bounds
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.Add(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
}
