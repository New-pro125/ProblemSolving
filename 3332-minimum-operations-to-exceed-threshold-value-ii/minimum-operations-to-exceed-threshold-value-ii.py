class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
        res = 0
        while len(heap) >=2:
            first, second = heapq.heappop(heap), heapq.heappop(heap)
            if first >= k:
                break
            heapq.heappush(heap, first * 2 + second)
            res +=1
        return res