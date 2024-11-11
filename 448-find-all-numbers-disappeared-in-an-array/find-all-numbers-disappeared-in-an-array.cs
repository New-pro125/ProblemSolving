public class Solution {
    public IList<int> FindDisappearedNumbers(int[] nums) {
        List<int> missingNumber = new List<int>();
        int n = nums.Length;
        int[] freq = new int[n];
        foreach(int number in nums){
            freq[number-1]++;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                missingNumber.Add(i+1);
            }
        }
        return missingNumber;
    }
}