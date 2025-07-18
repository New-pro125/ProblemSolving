using ll = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int, vector<int>> firstHalf;
        priority_queue<int, vector<int>, std::greater<int>> secondHalf;
        int n = nums.size() / 3;
        ll sum = 0;
        std::vector<ll> part1(n+1);
        for(int i =0;i<n;i++){
            sum += nums[i];
            firstHalf.push(nums[i]);
        }
        part1[0] = sum;
        for(int i = n;i<2*n;i++){
            sum+=nums[i];
            firstHalf.push(nums[i]);
            sum-=firstHalf.top();
            firstHalf.pop();
            part1[i - (n-1)] = sum;
        }
        ll part2Sum = 0;
        for(int i = n * 3 - 1;i >= n * 2;--i){
            part2Sum +=nums[i];
            secondHalf.push(nums[i]);
        }
        ll ans = part1[n] - part2Sum;
        for(int i = n*2 -1 ;i>=n;--i) {
            part2Sum +=nums[i];
            secondHalf.push(nums[i]);
            part2Sum -=secondHalf.top();
            secondHalf.pop();
            ans = min(ans,part1[i-n] - part2Sum);
        }
        return ans;
    }
};