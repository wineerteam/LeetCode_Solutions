class Solution {
private:
    bool dfs(vector<int>&vis,vector<vector<int>>&adj,int node, int dest){
         if( node==dest){
            return true;
         }
        vis[node]=1;
        for(auto it:adj[node]){
            if( !vis[it]){
                vis[it]=1;
                if(dfs(vis,adj,it,dest)) 
                return true;
            }
        }

return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

         // dfs 
         vector<int>vis(n,0);
         
        return dfs(vis,adj,src,dest);

            }
};