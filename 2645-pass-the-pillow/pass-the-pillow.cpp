class Solution {
public:
    int passThePillow(int n, int time) {
        // 1 --> N  (N-1) && N -> 1 (N-1)
        int flag= time/(n-1);
        if(flag%2){
            return n-(time%(n-1));
        }
        else
            return time%(n-1)+1;
    }
};