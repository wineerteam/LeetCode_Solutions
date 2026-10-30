class Solution {
    #define ll long long 
public:
    vector<int> getAverages(vector<int>& arr, int k) {

        int n=arr.size();
        vector<int>ans(arr.size(),-1);

        // base case 
     if( 2*k+1>arr.size())return ans;

        ll wsum=0;
        ll window=2LL*k+1;

        for(int i=0; i<window; i++)
                wsum+=arr[i];
        
        ans[k]=wsum/window;

        for(int i=k+1; i<n-k; i++){
           wsum+=arr[i+k]-arr[i-k-1];
           ans[i]=wsum/window;

        }

        return ans;
    }
};

// using sliding window optimze space o(N ) to O(1)