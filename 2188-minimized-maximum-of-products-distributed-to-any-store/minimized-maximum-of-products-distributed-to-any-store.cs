public class Solution {
    public bool IsDistributable(int x,int[] quantities ,int n){
     int stores = 0;
     foreach(int quantity in quantities){
        stores +=quantity/x;
        if(quantity%x!=0) stores++;
        if(stores > n) return false;
     }
     return stores <=n;
    }
    public int MinimizedMaximum(int n, int[] quantities) {
        int max = 0,sum = 0;
        foreach(int quantity in quantities){
            max = Math.Max(quantity,max);
            sum += quantity;
        }
        int left = 1,right = max,res = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(IsDistributable(mid,quantities,n)){
                res = mid;
                right = mid-1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
}