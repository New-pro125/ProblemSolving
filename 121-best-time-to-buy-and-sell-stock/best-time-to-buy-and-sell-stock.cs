public class Solution {
    public int MaxProfit(int[] prices) {
        int minIdx = 0,maxIdx = 0;
        int profit = 0 ;
        for(int i=1;i<prices.Length;i++){
            if(prices[minIdx] > prices[i]){
                minIdx = i;
                maxIdx = i;
            }
            if(prices[maxIdx]<prices[i] && minIdx <i){
                maxIdx = i;
            }
            profit = Math.Max(profit,prices[maxIdx]-prices[minIdx]);
        }
        return profit;
    }
}