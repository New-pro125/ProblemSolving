class Solution {
    private int[] coins;
    private long k;

    public long findKthSmallest(int[] coins, long k) {
        this.coins = coins;
        this.k = k;
        
        long left = 1;
        long right = (long) 1e11;
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (count(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    private long count(long maxValue) {
        long count = 0;
        int n = coins.length;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            long lcmVal = 1;
            
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    lcmVal = lcm(lcmVal, coins[i]);
                    if (lcmVal > maxValue) break;
                }
            }
            
            if (lcmVal > maxValue) continue;
            
            int bits = Integer.bitCount(mask);
            if (bits % 2 == 1) {
                count += maxValue / lcmVal;
            } else {
                count -= maxValue / lcmVal;
            }
        }
        
        return count;
    }
    
    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
    
    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

}