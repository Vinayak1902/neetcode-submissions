class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m,n = len(grid), len(grid[0])
        dirs = [[-1,0],[0,-1],[1,0],[0,1]]
        
        def dfs(i,j):
            for dir in dirs:
                x,y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n and grid[x][y]!=-1 and grid[x][y]>grid[i][j]:
                    grid[x][y] = grid[i][j] + 1
                    dfs(x,y)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    dfs(i,j)
        