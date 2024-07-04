vector<int> result(100,-1);
class Solution {
public:
    int tribonacci(int n) {
     if(n==0||n==1)
        return n;
        if (n==2)
            return 1;
        if(result[n]!=-1)
            return result[n];
        result[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        return result[n];
    }
};