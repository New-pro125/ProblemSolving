class Solution:
    def findDifferentBinaryString(self, nums: List[str] = ["111", "011", "001"]) -> str:
        strSet = {s for s in nums}
        def backtrack(i:int,curr_str:str)->str:
            if i==len(nums):
                res =  "".join(curr_str)
                return None if res in strSet else res
            res = backtrack(i+1,curr_str)
            if res: return res
            curr_str[i] = "1"
            res = backtrack(i + 1, curr_str)
            if res :return res
        return backtrack(0,["0" for s in nums])