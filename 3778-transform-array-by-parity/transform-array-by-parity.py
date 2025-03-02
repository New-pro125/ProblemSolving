class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        res = []
        even = 0;odd = 0
        for num in nums:
            if num %2:
                odd +=1
            else:
                even +=1
        res = [0 for i in range(even)] + [1 for i in range(odd)]
        return res