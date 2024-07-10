class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0 ;
        for(int i =0;i<logs.size();i++){
            if(logs[i]=="../") steps=max(0,steps-1);
            else if(logs[i]=="./") continue;
            else
                steps+=1;
        }
        return steps;
    }
};