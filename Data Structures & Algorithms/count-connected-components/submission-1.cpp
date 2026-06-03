class Solution {
public:
    void dfs(vector<bool>& visited,int node,vector<vector<int>>& adj){
        visited[node] = true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(visited,neighbor,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(visited,i,adj);
                count++;
            }
        }
        return count;
    }
};
