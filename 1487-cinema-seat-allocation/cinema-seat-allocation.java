class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
       Map<Integer,Integer> bitsSeats = new HashMap<>();
        for(int i = 0;i<reservedSeats.length;i++){
            int r = reservedSeats[i][0]; int c =  reservedSeats[i][1];
            bitsSeats.merge(r,1 << c, (a,b) -> a | b);
            
        }
        int ans = (n - bitsSeats.size())* 2;
        for(int bits: bitsSeats.values()){
            if((bits & (15 << 2)) == 0 && (bits & (15 << 6)) == 0) ans+=2;
            else if((bits & (15 << 2)) == 0 || (bits & (15 << 4)) == 0 || (bits & (15 << 6)) == 0) ans++;
        }
        return ans;
    }
}