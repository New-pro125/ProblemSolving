class Solution {
public: 
    void cleanString(string &s){
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]>=65&&s[i]<=90)
                res+= (char) tolower(s[i]);
            else if(!(s[i]>=97&&s[i]<=122 ||s[i]>=48&&s[i]<=57))
                   continue;
            else 
                res+=s[i];
        }
        s =res;
    }
    bool isPalindrome(string s) {
        cleanString(s);
        cout<<s<<'\n';
        int i =0,j =s.size()-1;
        while(i<=j){
            if(tolower(s[i])!=tolower(s[j])) {cout<<s[i]<<" "<<s[j]<<'\n';return false;}
            i++;
            j--;
        }
        return true;
    }
};