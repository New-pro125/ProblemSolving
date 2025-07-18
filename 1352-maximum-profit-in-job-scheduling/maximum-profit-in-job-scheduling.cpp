class Solution {
private:
    vector<int> dp;

    int jobSchedulingHelper(int idx, const vector<vector<int>> &intervals) {
        if (idx == intervals.size())
            return 0;
        if (~dp[idx])
            return dp[idx];

        // Option 1: Skip this job
        int ans = jobSchedulingHelper(idx + 1, intervals);

        // Option 2: Take this job and find the next compatible job using lower_bound
        int target = intervals[idx][1]; // current job's end time
        auto it = lower_bound(intervals.begin() + idx + 1, intervals.end(), target,
                              [](const vector<int> &interval, int value) {
                                  return interval[0] < value;
                              });
        int nextIdx = it - intervals.begin();

        // Include current job profit + recurse from nextIdx
        ans = max(ans, intervals[idx][2] + jobSchedulingHelper(nextIdx, intervals));
        return dp[idx] = ans;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp = vector<int>(n + 1, -1);

        vector<vector<int>> intervals;
        for (int i = 0; i < n; ++i) {
            intervals.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort by start time to ensure binary search works
        sort(intervals.begin(), intervals.end());

        return jobSchedulingHelper(0, intervals);
    }
};
