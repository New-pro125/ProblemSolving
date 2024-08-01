class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            string res = details[i].substr(details[i].size()-4,2);
            if(stoi(res)>60) cnt++;
        }
        return cnt;
    }
};