public class Solution {
    public int[] MaximumBeauty(int[][] items, int[] queries) {
        Array.Sort(items,(a,b) => a[0].CompareTo(b[0]));
        int[] maxBeautyQueries = new int[queries.Length];
        int[] maxBeauty = new int[items.Length];
        for(int i=0;i<items.Length;i++){
            maxBeauty[i] = Math.Max(((i>0) ? maxBeauty[i-1]: items[0][1]),items[i][1]);
        }

        for(int i = 0;i<queries.Length;i++){
            int start = 0, end = items.Length-1,idx = -1;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(items[mid][0]<=queries[i]){
                    start = mid+1;
                    idx = mid;
                }
                else {
                    end = mid -1;
                }
            }
            maxBeautyQueries[i] = idx>=0 ? maxBeauty[idx] : 0;
        }
        return maxBeautyQueries;
    }
}