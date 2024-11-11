public class Solution {
    public int MaximumPopulation(int[][] logs) {
        int[] count = new int[2055];
        for(int i=0;i<logs.Length;i++){
            for(int j =logs[i][0];j<logs[i][1];j++){
                count[j]++;
            }
        }
        int maxPopulation = 0, maxIndex = 0;
        for(int i=0;i<count.Length;i++){
            if(maxPopulation<count[i]){
                maxPopulation = count[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}