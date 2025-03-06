class Solution:
    def minimumObstacles(
        self, grid: List[List[int]] = [[0, 1, 1], [1, 1, 0], [1, 1, 0]]
    ) -> int:
        rows, cols = len(grid), len(grid[0])
        min_heap = [(0, 0, 0)]  # (obstacles,r,c)
        visited = set([(0, 0)])  #
        while min_heap:
            obstacles, r, c = heapq.heappop(min_heap)
            nei = [[r + 1, c], [r - 1, c], [r, c + 1], [r, c - 1]]
            if (r, c) == (rows - 1, cols - 1):
                return obstacles
            for nr, nc in nei:
                if nr >= rows or nr < 0 or nc >= cols or nc < 0 or (nr, nc) in visited:
                    continue

                heapq.heappush(min_heap, (obstacles + grid[nr][nc], nr, nc))
                visited.add((nr, nc))

        return -1