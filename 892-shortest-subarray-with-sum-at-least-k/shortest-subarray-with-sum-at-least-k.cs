public class Solution {
    private int FindCandidateIndex(List<Tuple<long,int>> nums,long target){
        int left = 0,right = nums.Count-1;
        while(left <=right){
            int mid = left +(right -left)/2;
            if(nums[mid].Item1 <=target){
                left = mid +1;
            }
            else {
                right = mid -1;
            }
        }
        return right;
    }
    public int ShortestSubarray(int[] nums, int k) {
        int n = nums.Length;
        List<Tuple<long,int>>cumulativeSumStack = new List<Tuple<long,int>>();
        cumulativeSumStack.Add(new Tuple<long,int>(0L,-1));
        long runningCumulativeSum =0;
        int shortestSubarrayLength = int.MaxValue;
        for(int i =0;i<n;i++){
            runningCumulativeSum +=nums[i];
            // Remove Entries From Stack larger than current Cumulative Sum
            while(cumulativeSumStack.Count > 0 && runningCumulativeSum <= cumulativeSumStack[cumulativeSumStack.Count-1].Item1) {
                cumulativeSumStack.RemoveAt(cumulativeSumStack.Count -1);
            }
            cumulativeSumStack.Add(new Tuple<long,int>(runningCumulativeSum,i));
            int candidateIndex = FindCandidateIndex(cumulativeSumStack,runningCumulativeSum -k);
            if(candidateIndex !=-1){
                shortestSubarrayLength = Math.Min(shortestSubarrayLength,i - cumulativeSumStack[candidateIndex].Item2);
            }
        }
        return shortestSubarrayLength == int.MaxValue ? -1 : shortestSubarrayLength;
    }
}