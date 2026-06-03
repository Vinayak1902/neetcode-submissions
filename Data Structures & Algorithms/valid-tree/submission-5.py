class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        visited = [False]*n
        adj = [[] for i in range(n)]
        for src,dst in edges:
            adj[dst].append(src)
            adj[src].append(dst)
        def isCycle(node,parent):
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    if isCycle(neighbor,node):
                        return True
                elif neighbor != parent:
                    return True
            return False
        if isCycle(0,-1):
            return False
        for v in visited:
            if not v:
                return False
        return True