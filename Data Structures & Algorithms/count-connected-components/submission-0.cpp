class Solution {
public:
    void dfs(int src,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis){
        vis[src]=true;
        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    } 
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt=0;
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt; 
    }
};
