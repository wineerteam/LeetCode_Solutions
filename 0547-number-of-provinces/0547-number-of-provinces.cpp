class Solution {
private:
    void bfs (int i, vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
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
             bfs(i,vis,adj);
            cnt++;}
        } 
        return cnt;       
    }
};

// es me just hme bfs and dfs call krna h. or visite krna h. ek external for loop se ek bar loop start hoga to jb tk conneceted hoga tb  tak chalega or agar diconnect huta to fir se bfs call hoga or cnt increaes hoga
