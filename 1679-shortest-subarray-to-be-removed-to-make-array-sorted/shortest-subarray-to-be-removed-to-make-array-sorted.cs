public class Solution {
    public int FindLengthOfShortestSubarray(int[] arr) {
        int right = arr.Length -1;
        while(right > 0  && arr[right]>=arr[right-1]) {
            right--;
        }
        int ans = right;
        int left = 0;
        while(left <right && (left==0 || arr[left-1] <=arr[left])){
            while(right < arr.Length && arr[left] > arr[right]) {
                right ++;
            }
            ans = Math.Min(ans,right-left-1);
            left ++;
        }
        return ans;
    }
}