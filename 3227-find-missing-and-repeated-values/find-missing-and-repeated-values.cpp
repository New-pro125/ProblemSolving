class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> freq(n*n);
        std::vector<int>arr(2);
        for(const std::vector<int>& r:grid){
            for(const int & c: r){
                freq[c-1]+=1;
                if(freq[c-1] ==2){
                    arr[0] = c;
                }
            }
        }
        for(size_t i = 0;i<freq.size();i++){
            if(!freq[i]) {
                arr[1] = i+1;
                return arr;
            }
        }
        return {-1,-1};
    }
};