class Solution {
    #define ll long long 
public:
    vector<int> getAverages(vector<int>& arr, int k) {

        int n=arr.size();
        vector<int>ans(arr.size(),-1);
        vector<ll>psum(arr.size(),0);

        // base case 
     if( 2*k+1>arr.size())return ans;


        psum[0]=arr[0];
        for(int i=1; i<arr.size(); i++){
            psum[i]=psum[i-1]+arr[i];
        }

        for(int i=k; i<n-k; i++){
           ll sum=psum[i+k];

           if(i-(k+1)>=0 )
           sum=sum-psum[i-(k+1)];
           
           ans[i]=sum/(2LL*k+1);

        }

        return ans;
    }
};