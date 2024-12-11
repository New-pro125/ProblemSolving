class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        # sweep line algorithm : 
        numbers = []
        for num in nums:
            numbers.append((num-k,1))
            numbers.append((num+k+1,-1))
        numbers.sort()
        max_beauty = 0
        current_count =0
        for value,effect in numbers:
            current_count +=effect
            max_beauty = max(max_beauty,current_count)
        return max_beauty