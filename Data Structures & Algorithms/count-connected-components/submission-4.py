class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        visited = [False]*n
        num = 0
        def dfs(node):
            visited[node] = True
            for nei in adj[node]:
                if visited[nei] is False:
                    dfs(nei)
        for i in range(n):
            if visited[i] is False:
                num += 1
                dfs(i)
        return num