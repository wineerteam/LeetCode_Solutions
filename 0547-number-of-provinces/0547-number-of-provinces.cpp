class Solution {
private:
    void dfs(int node, vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {

        // convete into adj list
        int m=mat.size();
        int n=mat[0].size();


        vector<vector<int>>adj(m);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // ab call krte h. dfs ko 
        int cnt=0;
        vector<int>vis(adj.size(),0);
        for(int i=0; i<adj.size(); i++){
            if(!vis[i]){
            dfs(i,vis,adj);
            cnt++;}
        } 
        return cnt;       
    }
};