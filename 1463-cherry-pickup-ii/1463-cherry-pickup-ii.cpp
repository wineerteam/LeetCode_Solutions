class Solution {
    int n,m;
    int dp[71][71][71];
         int solve(vector<vector<int>>& arr, int r, int c1, int c2){
            if(r>=m) return 0;

            if( dp[r][c1][c2] != -1)return dp[r][c1][c2];

            int ans=0;
            int chery=arr[r][c1];
            if( c1!=c2){   //      robot 1 and robot2 different 
                chery +=arr[r][c2];
            }

            for(int i=-1; i<=1; i++){
                for(int k=-1; k<=1; k++){
                    int nr=r+1;
                    int nc1=c1+i;
                    int nc2=c2+k;
                 if( nc1>=0 && nc1<=n-1 && nc2>=0 && nc2<=n-1 )
                  ans=max(ans,solve(arr,nr,nc1,nc2));
                }
            }
         return  dp[r][c1][c2]=chery+ans;
         }
public:
    int cherryPickup(vector<vector<int>>& arr) {
    
      memset(dp,-1,sizeof(dp));
       n=arr[0].size();
       m=arr.size();
        return solve(arr,0,0,n-1);
        
    }
};