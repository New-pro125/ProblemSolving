class Solution {
public:
    int reverse(int x) {
        long long y =0;
        string s = to_string(x);
        if(s[0] == '-'){
            std::string t = s.substr(1);
            std::reverse(t.begin(),t.end());
            y = stol(t);
            y=-y;
        }
        else { 
            std::reverse(s.begin(),s.end());
            y = stol(s);
        }
        if(y >INT_MAX||y<INT_MIN)  y=0;
        return (int)y;
    }
};