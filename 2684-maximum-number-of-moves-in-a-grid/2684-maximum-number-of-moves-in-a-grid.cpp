class Solution {
    int n,m;
    int dp[1001][1001];
    int solve(vector<vector<int>>& arr, int r, int c){
            if( r>=n || r<0 || c>=m || r<0)return 0;
             int ans1=0;

                if( dp[r][c] != -1)return dp[r][c];

             for(int i=-1; i<=1; i++){
                int nr=r+i;
                int nc=c+1;
                // check out of bound                 
                if( nr<=n-1 && nr>=0 && nc<=m-1 &&  nc>=0 && arr[nr][nc]>arr[r][c]){
                    //   ans1++;
                    ans1 =max(ans1,1+solve(arr,nr,nc));
                   

                }
             }
        return dp[r][c]=ans1;
       
    }
public:
    int maxMoves(vector<vector<int>>& arr) {

    n=arr.size();
    m=arr[0].size();
    
    memset(dp,-1,sizeof(dp));
   

/// colum pr dfs call kro

int ans=0;

 for(int i=0 ; i<n; i++){
    ans=max(ans,solve(arr,i,0));
 }

 return ans;
        
    }
};

