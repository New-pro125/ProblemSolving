class Solution:
    def maximumLength(self, s: str) -> int:
        
        def is_special(sub:str)->bool:
            return(len(set(sub)))==1
        
        n = len(s)
        max_length = -1
        for length in range(1,n+1):
            substr_count = {}
            for i in range(n-length+1):
                substring = s[i:i+length]
                if is_special(substring):
                    substr_count[substring] = substr_count.get(substring,0) + 1
                    if substr_count[substring] >=3:
                        max_length = max(max_length,length)
        return max_length