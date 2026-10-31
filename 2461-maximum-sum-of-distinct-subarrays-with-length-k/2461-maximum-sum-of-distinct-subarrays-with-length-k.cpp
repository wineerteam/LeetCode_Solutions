class Solution {
    #define ll long long
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        ll ans=0,temp=0;
        unordered_map<int,int>freq;
        for(int i=0; i<k; i++){
            temp+=arr[i];
            freq[arr[i]]++;
        }
        if( freq.size()==k)ans=temp;
        for(int i=k; i<n; i++){
            temp+=arr[i]-arr[i-k];
            freq[arr[i]]++;
            freq[arr[i-k]]--;
            if(freq[arr[i-k]]==0)
            freq.erase(arr[i-k]);
            if(freq.size() == k)
            {
                if( ans<temp)ans=temp;
            }
        }
       

        return ans;
    }
};