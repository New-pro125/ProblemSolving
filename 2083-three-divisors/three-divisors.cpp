class Solution {
public:
    bool isThree(int n) {
        int divs =0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divs++;
                divs+=(n/i!=i);
            }
        }
        return divs==3;
    }
};