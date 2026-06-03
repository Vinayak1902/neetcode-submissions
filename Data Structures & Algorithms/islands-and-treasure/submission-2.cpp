class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(auto &dir: dirs){
                int r = row + dir[0], c=col+dir[1];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==INT_MAX){
                    q.push({r,c});
                    grid[r][c] = grid[row][col]+1;
                }
            }
        }
    }
};
