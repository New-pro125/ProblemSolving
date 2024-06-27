class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if len(s)==0:
            return 0
        isNegative =False
        res = 0 
        if s[0] =='-' or s[0]=='+':
            if s[0]=='-':
                isNegative =True
            s = s[1:].lstrip('0')
        else:
            s = s.lstrip('0')
        for i in range(len(s)):
            temp = ord(s[i])-ord('0')
            if temp>=0 and temp <=9:
                res*=10
                res+=temp   
            else:
                break
        if isNegative:
            res = -res 
        if res < -2147483648:
            res = -2147483648
        elif res > 2147483647:
            res = 2147483647
        return res