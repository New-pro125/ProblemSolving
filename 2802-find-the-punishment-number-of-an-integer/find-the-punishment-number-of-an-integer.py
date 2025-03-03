class Solution:
    def punishmentNumber(self, n: int) -> int:
        def partition(i,cur:int,target:int,str_number:str):
            if i == len(str_number) and cur == target:
                return True
            for j in range(i,len(str_number)):
                if partition(j+1,cur + int(str_number[i:j+1]) ,target,str_number):
                    return True
            return False
        res = 0
        for i in range(1, n + 1):
            if partition(0,0,i,str(i*i)):
                res += i * i
        return res