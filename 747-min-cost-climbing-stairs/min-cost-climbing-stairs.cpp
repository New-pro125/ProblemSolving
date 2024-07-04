class Solution {
    private:
    vector<int>dp;
    int MinCost(const vector<int>&cost,int index){
        if(index>=cost.size())
            return (index==cost.size())?0:INT16_MAX;
        int &ret=dp[index];
    if(~ret)
        return ret;
        return ret=min(MinCost(cost,index+1)+cost[index],MinCost(cost,index+2)+cost[index]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size()+1,-1);
        return min(MinCost(cost,1),MinCost(cost,0));
    }
};