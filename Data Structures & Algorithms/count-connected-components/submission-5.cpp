class Solution {
    void dfs(vector<vector<int>>& adj,int i,vector<bool>& visited){
        visited[i] = true;
        for(int neighbor:adj[i]){
            if(visited[neighbor]==false) dfs(adj,neighbor,visited);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int res = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                res++;
                dfs(adj,i,visited);
            }
        }
        return res;
    }
};
