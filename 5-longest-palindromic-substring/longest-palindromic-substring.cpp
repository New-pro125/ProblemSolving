class Solution {
    int check(string t,int s,int e){
        while(s>=0&&e<t.size()&&t[s]==t[e]) s--,e++;
        return e-s-1;
    }
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
            string su="";
            int start=0,end=0,len=0;
            for(int i=0;i<s.size();i++){
                int len1=check(s,i,i);
                int len2=check(s,i,i+1);
                 len=max(len1,len2);
                if(len>end-start){
                    start=i-(len-1)/2;
                    end=i+(len)/2;
                }
            }
            su=s.substr(start,end-start+1);
            return su;
    }

};