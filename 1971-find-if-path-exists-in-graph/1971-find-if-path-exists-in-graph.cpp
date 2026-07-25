class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        
        // converte into adj list
        vector<vector<int>> adj(n);
        for( auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // queue 
        queue<int>q;
        vector<int>vis(n,0);
        q.push(src);
        vis[src]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            if( node==dest)return true;
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }




        return false;
    }
};