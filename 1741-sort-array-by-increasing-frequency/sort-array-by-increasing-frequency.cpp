class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>freq(201);
        for(size_t i =0;i<nums.size();i++){
            freq[nums[i]+100].first+=1;
            freq[nums[i]+100].second = nums[i]; 
        }
        sort(freq.begin(),freq.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            if(a.first==b.first) return a.second >b.second;
            return a.first<b.first;
        });
        vector<int>arr;
        for(int i = 0;i<=200;i++){
            while(freq[i].first--) arr.push_back(freq[i].second);
        }

        return arr;
    }
};