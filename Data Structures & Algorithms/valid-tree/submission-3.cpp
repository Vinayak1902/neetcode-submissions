class Solution {
    /* 1. no of edges equals to no of nodes-1
       2. there should be no cycle
       3. all nodes must be connected
    */
    bool dfs(vector<vector<int>> &adj,vector<bool>& visited,int node,int parent){
        visited[node]=true;
        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                if(dfs(adj,visited,neighbor,node)) return true;
            }
            else if(neighbor!=parent) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1)) return false;
            }
        }
        for(auto v:visited){
            if(!v) return false;
        }
        return true;
        
    }
};
