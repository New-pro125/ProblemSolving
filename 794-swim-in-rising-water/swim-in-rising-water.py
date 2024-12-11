class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visit = set()
        min_heap = [[grid[0][0],0,0]] # (time/Max-height,r,c)
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        visit.add((0,0))
        while min_heap:
            result = heapq.heappop(min_heap)
            [time, row ,column] = result
            if row == n-1 and column == n-1 : 
                return time
            for dr,dc in directions:
                neighbour_row , neighbour_column = row + dr,column + dc
                if neighbour_row < 0 or neighbour_column < 0 or neighbour_row == n or neighbour_column == n or (neighbour_row,neighbour_column) in visit : 
                    continue
                visit.add((neighbour_row,neighbour_column))
                heapq.heappush(min_heap,[max(time,grid[neighbour_row][neighbour_column]),neighbour_row,neighbour_column])