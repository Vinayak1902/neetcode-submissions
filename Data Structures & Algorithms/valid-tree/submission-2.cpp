class Solution {
    bool dfs(int node,int parent,vector<bool>& visited,vector<vector<int>>& adj){
        visited[node]=true;
        for(auto& neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,node,visited,adj)) return true;
            }
            else if(parent!=neighbor) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(const auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if(dfs(0,-1,visited,adj)) return false;
        for(auto v:visited) if(!v) return false;
        return true;
    }
};
