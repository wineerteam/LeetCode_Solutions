class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fght, int src, int dst, int k) {

      unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:fght){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
        }
         vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        dist[src][0]=0;
        pq.push({0,src,0});
        
        
        while(!pq.empty()){
           auto [d, node, stops] = pq.top();
            pq.pop();

             if (node == dst)
                return d;
            if (stops == k + 1)
                continue;
            if (d > dist[node][stops])
                continue;
            if( stops==k+1)continue;
            for(auto &vec:adj[node]){
                auto adjNode=vec.first;
                auto dest=vec.second;
                if (d + dest < dist[adjNode][stops + 1]){
                    dist[adjNode][stops+1]=d+dest;
                    pq.push({d+dest,adjNode,stops+1});
                }
            }
        }

        
        return -1;
    }
};