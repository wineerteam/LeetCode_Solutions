
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // pahle dfs use krte h
        int n=rooms.size();
        vector<int>vis(n,0);
        dfs(0,vis,rooms);
        for(auto it:vis){
            if(it==false)return false;
        }
        return true;
    }

};