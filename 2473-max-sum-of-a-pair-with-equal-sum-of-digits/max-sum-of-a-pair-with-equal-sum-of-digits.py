class Solution:
    def sumNumber(self, num: int) -> int:
        res = 0
        while num:
            res += num % 10
            num //= 10
        return res
    def maximumSum(self, nums: List[int]) -> int:
        digit_sum_map = {}
        res = -1
        for num in nums:
            digit_sum = self.sumNumber(num)
            if digit_sum in digit_sum_map:
                res = max(res,num + digit_sum_map[digit_sum])
                digit_sum_map[digit_sum] = max(digit_sum_map[digit_sum],num)
            else:
                digit_sum_map[digit_sum] = num
        return res