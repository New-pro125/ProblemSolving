class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>arr(numRows);
        bool flag = true;
        int i =0 ;
        while(i<s.size()){
            if(flag){
                for(int j = 0;j<numRows;j++){
                    if(i>=s.size()) break;
                    arr[j].push_back(s[i]);
                    i++;
                }
                
            }
            else{
                for(int j = numRows-2;j>=1;j--){
                    if(i>=s.size()) break;
                    arr[j].push_back(s[i]);
                    i++;
                }
            }
            flag=!flag;
        }
        string result;
        for(int i = 0;i<numRows;i++){
            for(int j = 0;j<arr[i].size();j++){
                cout<<arr[i][j]<<' ';
                result+=arr[i][j];
            }
            cout<<'\n';
        }
        return result;
    }
};