class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj = [[] for i in range(n)]
        for src,dst in edges:
            adj[src].append(dst)
            adj[dst].append(src)
        visited = [False]*n

        def dfs(node,parent):
            visited[node] = True
            for nei in adj[node]:
                if not visited[nei]:
                    if dfs(nei,node):
                        return True
                elif parent != nei:
                    return True
            return False
        numComponents = 0
        for i in range(n):
            if visited[i] == False:
                numComponents += 1
                if numComponents > 1:
                    return False
                if dfs(i,-1):
                    return False
        return True