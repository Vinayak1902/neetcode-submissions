class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        q = deque()
        m,n = len(grid), len(grid[0])
        dirs = [[-1,0],[0,-1],[0,1],[1,0]]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    q.append((i,j))
        while q:
            node = q.popleft()
            i, j = node[0], node[1]
            for dir in dirs:
                x,y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n:
                    if grid[x][y] != -1 and grid[x][y] > grid[i][j]:
                        grid[x][y] = grid[i][j] + 1
                        q.append((x,y))