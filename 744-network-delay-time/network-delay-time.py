class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    # Build adjacency list 
        graph = collections.defaultdict(list)
        for src,dest,dist in times:
            graph[src].append((dest,dist))
        min_heap = [(0,k)]
        visited = set()
        time = 0
        while min_heap:
            current_time,current_node = heapq.heappop(min_heap)

            if current_node in visited:
                continue
            visited.add(current_node)
            time = max(time,current_time)
            for neighbour,weight in graph[current_node]:
                if neighbour not in visited:
                    heapq.heappush(min_heap,(current_time + weight,neighbour))
        return time if len(visited) == n else -1
                