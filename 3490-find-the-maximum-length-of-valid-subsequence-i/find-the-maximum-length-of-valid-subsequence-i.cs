public class Solution {
    public int MaximumLength(int[] nums) {
        int n = nums.Length ;
        int even = 0, odd = 0;
        foreach(int num in nums){
            if(num % 2 == 0)
            {
                even++;
            }
            else 
            {
                odd++;
            }
        }
        int evenDp = 0,oddDp = 0;
        foreach(int num in nums){
            if(num % 2 ==0){
                evenDp = Math.Max(evenDp,oddDp + 1);
            }
            else 
            {
                oddDp = Math.Max(oddDp,evenDp + 1);
            }
        }
        return Math.Max(Math.Max(even,odd),Math.Max(evenDp,oddDp));
    }
}