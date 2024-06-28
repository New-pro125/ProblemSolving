class Solution:
    def partitionString(self, s: str) -> int:
        last = 1
        freq = [0]*26
        
        for i in range(len(s)):
            if freq[ord(s[i])-ord('a')]:
        
                freq = [0 for _ in freq]
                last+=1
        
            freq[ord(s[i])-ord('a')]+=1
        
        return last