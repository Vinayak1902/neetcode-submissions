class Solution {
    void dfs(vector<bool>& visited,int node,vector<vector<int>>& adj){
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]) dfs(visited,neighbor,adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,i,adj);
                count++;
            }
        }
        return count;
    }
};

