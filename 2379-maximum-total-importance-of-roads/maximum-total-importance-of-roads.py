class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        freq = [[0,i] for i in range(n)]
        vals = [0]*n
        for i in range(len(roads)):
            freq[roads[i][0]][0]+=1
            freq[roads[i][1]][0]+=1
        freq.sort()
        while n>0:
            vals[freq[n-1][1]] = n;
            n-=1
        res = 0
        for i in range(len(roads)):
            res+=(vals[roads[i][0]]+vals[roads[i][1]])
        return res
        