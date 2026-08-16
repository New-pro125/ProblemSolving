class Solution {
    public boolean stoneGameIX(int[] stones) {
      if(stones.length == 1)
        return false;  
      int[] freq = new int[3];
      for(int i = 0;i<stones.length;i++){
        freq[stones[i] % 3] ++;
      }
      
      if(freq[0] %2 == 0) {
        return Math.min(freq[1],freq[2]) >=1;
      }
      return Math.abs(freq[1] - freq[2]) > 2;
    }
}