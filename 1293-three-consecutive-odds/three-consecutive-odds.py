class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        times = 0 
        for i in range(len(arr)):
            if times==3: break
            if arr[i]%2: times+=1
            else : times = 0
        return times ==3
