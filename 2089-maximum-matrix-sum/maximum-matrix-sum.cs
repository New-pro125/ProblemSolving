public class Solution {
    public long MaxMatrixSum(int[][] matrix) {
        long sum = 0;
        int minAbsVal = int.MaxValue,negativeCount = 0;
        foreach(var row in matrix){
            foreach(int number in row){
                sum +=Math.Abs(number);
                if(number < 0) {
                    negativeCount ++;
                }
                minAbsVal = Math.Min(minAbsVal,Math.Abs(number));
            }
        }
        if(negativeCount %2!=0){
            sum -=2*minAbsVal;
        }
        return sum;
    }   
}