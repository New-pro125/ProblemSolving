class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        arr_map = {n:i for i,n in enumerate(arr)}
        dp = [[0]* n for _ in range(n)] #(i,j)
        res = 0
        for i in reversed(range(n-1)):
            for j in reversed(range(i+1,n)):
                prev , curr = arr[i],arr[j]
                nxt = prev + curr
                length = 2  
                if nxt in arr_map:
                    length = 1 + dp[j][arr_map[nxt]]
                    res = max(res,length)
                dp[i][j] = length     
        return res