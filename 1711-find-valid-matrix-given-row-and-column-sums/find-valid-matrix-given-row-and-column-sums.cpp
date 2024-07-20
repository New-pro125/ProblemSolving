class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> Mat(m, vector<int>(n)); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Mat[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= Mat[i][j];
                colSum[j] -= Mat[i][j];
            }
        }
        
        return Mat;
    }
};
