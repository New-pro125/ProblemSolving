class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        heap = []
        sum = 0
        for gift in gifts:
            sum +=gift
            heapq.heappush(heap,-gift)
        for i in range(k):
            top  = -heapq.heappop(heap)
            sum -=int(top - math.floor(math.sqrt(top)))
            heapq.heappush(heap,math.ceil(-math.sqrt(top)))
        return sum
            