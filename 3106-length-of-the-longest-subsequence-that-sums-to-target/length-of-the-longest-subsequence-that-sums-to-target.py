INF = 1e17
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        n =len(nums)
        dp = [[-INF]*(target+1) for _ in range(n+1)]
        dp[n][0] = 0
        for idx in range(n-1,-1,-1):
            for tar in range(target+1):
                if tar-nums[idx]>=0:
                    dp[idx][tar] = max(dp[idx][tar],1+dp[idx+1][tar-nums[idx]])
                dp[idx][tar] = max(dp[idx][tar],dp[idx+1][tar])
        return  -1 if dp[0][target]==-INF else dp[0][target]