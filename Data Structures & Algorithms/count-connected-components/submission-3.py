class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = [False]*n
        adj = [[] for i in range(n)]
        for src,dst in edges:
            adj[dst].append(src)
            adj[src].append(dst)
        def isCycle(node,parent):
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    isCycle(neighbor,node)
                    
        count = 0
        for i in range(n):
            if not visited[i]:
                isCycle(i,-1)
                count += 1
        return count