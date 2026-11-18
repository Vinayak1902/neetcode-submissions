class Solution {
    bool isCycle(int par, vector<bool>& visited,int i, vector<vector<int>>& adj){
        visited[i] = true;
        for(int neighbor:adj[i]){
            if(visited[neighbor]==false){
                if(isCycle(i,visited,neighbor,adj)) return true;
            }
            else{
                if(par != neighbor) return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        if(isCycle(-1,visited,0,adj)) return false;
        for(bool v:visited){
            if(v==false) return false;
        }
        return true;
    }
};
