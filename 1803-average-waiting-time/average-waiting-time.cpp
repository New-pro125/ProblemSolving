using ll = long long;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ll finish =0;
        ll wait = 0;
        ll start = 0;
        for(int i = 0;i<customers.size();i++){
            start = max((ll)customers[i][0],finish);
            finish = start+customers[i][1];
            wait +=finish-customers[i][0];
        }
        return (long double)wait/customers.size();
    }
};