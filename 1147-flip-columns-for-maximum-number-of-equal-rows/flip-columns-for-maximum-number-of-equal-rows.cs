public class Solution {
    public int MaxEqualRowsAfterFlips(int[][] matrix) {
        Dictionary<string,int> patternFrequency = new Dictionary<string,int>();
        foreach(var currentRow in matrix){
            StringBuilder patternBuilder = new StringBuilder();
            for(int col = 0 ;col < currentRow.Length;col++){
                if(currentRow[0]==currentRow[col]){
                    patternBuilder.Append("T");
                }
                else {
                    patternBuilder.Append("F");
                }
            }
            string rowPattern = patternBuilder.ToString();
            if(patternFrequency.ContainsKey(rowPattern)){
                patternFrequency[rowPattern]++;
            }
            else {
                patternFrequency[rowPattern] = 1;
            }
        }
    
    int maxFrequency = 0;
    foreach(var frequency in patternFrequency.Values){
        maxFrequency = Math.Max(frequency,maxFrequency);
    }
    return maxFrequency;
}
}