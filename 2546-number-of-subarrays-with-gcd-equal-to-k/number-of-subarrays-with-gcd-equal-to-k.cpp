class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for(size_t i=0;i<nums.size();i++){
            int g = 0;
            for(size_t j =i;j<nums.size();j++){
                g = __gcd(nums[j],g);
                if(g==k) res++;
            }
            
        }
        return res;
    }
};