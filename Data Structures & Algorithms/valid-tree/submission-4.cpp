class Solution {
    bool isCycle(int node,int parent,vector<bool>& visited,vector<vector<int>>& adj){
        visited[node] = true;
        for(int neighbor:adj[node]){
            if(visited[neighbor]==false){
                if(isCycle(neighbor,node,visited,adj)) return true;
            }
            else if(neighbor!=parent) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        if(isCycle(0,-1,visited,adj)) return false;
        for(bool v:visited){
            if(!v) return false;
        }
        return true;
    }
};
