class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>sol;
        for(size_t i =0;i<names.size();i++){
            sol.push_back({heights[i],names[i]});
        }
        sort(sol.begin(),sol.end());
        for(size_t i = 0;i<names.size();i++){
            names[i]= sol[names.size()-i-1].second;
        }
        return names;
    }
};