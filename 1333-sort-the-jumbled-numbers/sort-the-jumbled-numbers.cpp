class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multimap<int,int>sortie;
        vector<int>res;
        for(size_t i = 0;i<nums.size();i++){
            string temp, orig = to_string(nums[i]);
            for(size_t j =0;j<orig.size();j++){
                temp +=(char)(mapping[orig[j]-'0']+'0');
            }
            // sortie.insert(temp);
            sortie.insert({stoi(temp),nums[i]});
        }
        for(auto &[key,value]:sortie){
            std::cout<<key<<" -> "<<value<<"\n";
            res.push_back(value);
        }
        return res;
    }
};