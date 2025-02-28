class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        arr_set = set(arr)
        res = 0
        # Greedy Solution
        for i in range(len(arr)-1):
            for j in range(i+1,len(arr)):
                prev,curr = arr[i],arr[j]
                nxt = prev + curr
                length = 2
                while nxt in arr_set:
                    prev,curr = curr,nxt
                    nxt = prev + curr
                    length+=1
                res = max(res,length if length >=3 else 0)
        return res
