class Solution {
    int fast_mod(const int input, const int ceil) {
    return input >= ceil ? input % ceil : input;
}
public:
    int passThePillow(int n, int time) {
        // 1 --> N  (N-1) && N -> 1 (N-1)
        int flag= time/(n-1);
        if(fast_mod(flag,2)){
            return n-fast_mod(time,n-1);
        }
        else
            return fast_mod(time,n-1)+1;
    }
};