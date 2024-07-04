class Solution {
vector<int>dp;
private:
int fibSol(int n) {
        if(n<0)
            return 0;
       if(n==0||n==1)
        return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = fibSol(n-1)+fibSol(n-2); 
    }
public:
    int fib(int n) {
       dp = vector<int>(31,-1);
       return fibSol(n); 
    }
};