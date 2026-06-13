class Solution {
    bool dfs(int src,vector<bool> &vis,unordered_map<int,vector<int>> &adj){
        if(vis[src])return false;
        vis[src]=true;
        for(auto i:adj[src]){
            if(!dfs(i,vis,adj)){
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<bool> vis(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        if(!dfs(0,vis,adj)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};
