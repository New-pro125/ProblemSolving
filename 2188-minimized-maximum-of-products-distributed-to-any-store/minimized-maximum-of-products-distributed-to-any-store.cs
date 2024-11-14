public class Solution {
    public bool IsDistributable(int x,int[] quantities ,int n){
        int j = 0;
        int remaining = quantities[j];
        for(int i=0;i<n;i++){
            if(remaining <=x){
                j++;
                if(j==quantities.Length){
                    return true;
                }
                else {
                    remaining = quantities[j];
                }
            }
            else {
                remaining-=x;
            }
        }
        return false;
    }
    public int MinimizedMaximum(int n, int[] quantities) {
        int left =0,right = 0;
        foreach(int quantity in quantities){
            right = Math.Max(quantity,right);
        }
        while(left<right){
            int mid = left + (right-left)/2;
            if(IsDistributable(mid,quantities,n)){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
}