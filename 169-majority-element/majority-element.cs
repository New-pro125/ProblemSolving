public class Solution {
    public int MajorityElement(int[] nums) {
        Dictionary<int,int>Freq = new Dictionary<int,int>();
        int maxIdx = nums[0];
        foreach(var number in nums){
            if(Freq.ContainsKey(number))
                Freq[number]+=1;
            else 
                Freq.Add(number,1);
        }
        
        foreach(var pair in Freq){
            if(pair.Value > Freq[maxIdx]){
                maxIdx = pair.Key;
            }
        }
        return maxIdx;
    }
}