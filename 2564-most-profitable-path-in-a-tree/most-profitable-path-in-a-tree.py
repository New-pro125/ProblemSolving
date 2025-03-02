class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        # root = 0
        # how to know which direction to move ? 
        # Alice is easy , what about bob ?
        # Bob moves up , but has no Choice 
        # Bob Traversal First . (DFS)
        # Track time of Visits
        # only mark path to root ? 
        # Alice BFS , return MAX at end ?
        # Mark Nodes Visited
        # Edge Case , Both Visit same time 


        adj = defaultdict(list)
        for v1,v2 in edges:
            adj[v1].append(v2)
            adj[v2].append(v1)
        # Bob Simulation - DFS
        bob_times = {}
        def dfs(src,prev,time): # We don't need A visited Hashtable
            if src == 0 :
                bob_times[src ] = time
                return True
            for nei in adj[src]:
                if nei==prev: 
                    continue
                if dfs(nei,src,time+1):
                    bob_times[src] = time
                    return True
            return False
        dfs(bob,-1,0)
        # Alice Simulation - BFS
        q = deque([(0,0,-1,amount[0])]) # (node,time,prev,total_profit)
        res = float("-inf")
        while len(q)!=0:
            node,time,prev,total_profit = q.popleft()
            for nei in adj[node]:
                if nei == prev :
                    continue
                nei_profit = amount[nei]
                nei_time = time + 1
                if nei in bob_times:
                    if  nei_time > bob_times[nei]:
                        nei_profit = 0
                    elif nei_time == bob_times[nei]:
                        nei_profit //=2
                q.append((nei,nei_time,node,total_profit + nei_profit))
                if len(adj[nei]) ==1:
                    res = max(res,total_profit + nei_profit)
        return res
