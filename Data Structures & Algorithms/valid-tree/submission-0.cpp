class Solution {
    bool hasCycle(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(hasCycle(neighbor,node,adj,visited)) return true;
            }
            else if(neighbor!=parent) return false;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Conditions for tree -
        // 1. no. of edges should be equal to n-1
        // 2. there should be no cycle
        // 3. all nodes are connected
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(const auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        if(hasCycle(0,-1,adj,visited)) return false;
        //check if all nodes are visited or not
        for(bool v:visited){
            if(!v) return false;
        }
        return true;
    }
};
