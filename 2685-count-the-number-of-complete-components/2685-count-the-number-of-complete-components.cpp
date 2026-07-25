class Solution {
private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj,int &nodes,int &edge){
       vis[node] = 1;
       nodes++;                     // Ek node visit hua
       edge += adj[node].size();   // Is node ki degree add karo
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,nodes,edge);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         // convert into adj list
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // use dfs 
        vector<int>vis(n,0);
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if( !vis[i]){
                int edge=0;
                int nodes=0;
                dfs(i,vis,adj,nodes,edge);
                edge /=2;
                if(edge==nodes*(nodes-1)/2)
                  cnt++;
            }
        }
        return cnt;
        
    }
};