public class Solution {
    public bool PrimeSubOperation(int[] nums) { 
        int n  = nums.Length;
        
        //** Sieve of Eratosthenes
        bool[] primes = Enumerable.Repeat(true,1005).ToArray();
        primes[0] = primes[1] = false;
        for(int i=2;i<primes.Length;i++){
            if(primes[i]){
                for(int j = i*i;j<primes.Length;j+=i)
                    primes[j] = false;
            }
        }
        for(int i =0;i<n;i++){
            if(i==0){
                for(int j =1;j<nums[i];j++){
                    if(primes[nums[i]-j]){
                        nums[i] = j;
                        break;
                    }
                }
            }
            else {
                for(int j = nums[i-1]+1;j<nums[i];j++){
                    if(primes[nums[i]-j]){
                        nums[i]=j;
                    }
                }
            }
        }
        for(int i = 0;i<n-1;i++){
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
}