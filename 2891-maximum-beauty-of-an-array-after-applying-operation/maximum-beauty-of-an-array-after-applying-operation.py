class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        return len(nums:=sorted(nums))-reduce(lambda i,v:i+(v-nums[i]>2*k),nums,0)