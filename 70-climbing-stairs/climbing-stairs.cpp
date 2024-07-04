vector<int>arr(46,-1);
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 1;
            if(n<0)
            return 0;
            if(arr[n]!=-1)
                return arr[n];
         arr[n]=climbStairs(n-1)+climbStairs(n-2);
         return arr[n];
    }
};