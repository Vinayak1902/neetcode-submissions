class Solution {
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(auto &dir:dirs){
                int r = row + dir[0], c=col+dir[1];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==INT_MAX){
                    grid[r][c] = grid[row][col]+1;
                    q.push({r,c});
                }
            }
        }
        return;
    }
};
