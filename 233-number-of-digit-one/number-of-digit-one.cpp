using ll = long long;
std::vector<std::vector<std::vector<ll>>> dp;

class Solution {
    ll cnt_ones(const std::string &number, int idx, ll n1s, bool smaller) {
        if (idx == (int)number.size())
            return n1s;
        
        ll &ans = dp[idx][n1s][smaller];
        if (ans != -1)
            return ans;

        ans = 0;
        int limit = smaller ? 9 : (number[idx] - '0');

        for (int digit = 0; digit <= limit; ++digit) {
            ans += cnt_ones(number, idx + 1, n1s + (digit == 1), smaller || (digit < limit));
        }

        return ans;
    }

public:
    int countDigitOne(int n) {
    int sz = std::to_string(n).size();
    dp = std::vector<std::vector<std::vector<ll>>>(sz + 5, std::vector<std::vector<ll>>(sz + 5, std::vector<ll>(2, -1)));
           return (int) cnt_ones(std::to_string(n), 0, 0, 0);
    }
};