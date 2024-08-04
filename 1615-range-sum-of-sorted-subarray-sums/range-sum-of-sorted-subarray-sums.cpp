class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        multiset<int> st;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                st.insert(sum);
            }
        }
        int ans=0,mod=1e9+7;
        vector<int> summations;
        for(auto it:st)
            summations.push_back(it);
        for(int i=left;i<=right;i++){
            ans=(ans + summations[i-1])%mod;
        }
        return ans%mod;
    }
};