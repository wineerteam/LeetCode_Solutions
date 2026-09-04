class Solution {
    bool check(int mid,vector<int>& arr, int k){
        int sum=0;
        int cnt=1;
        for(int i=0; i<arr.size(); i++){
            
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return ( cnt<=k);
       
    }
public:
    int shipWithinDays(vector<int>& arr, int k) {
        
        int lo=*max_element(arr.begin(),arr.end());
        int hi=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,arr,k)){
                ans=mid;
                hi=mid-1;
            }
            else{
                  lo=mid+1;
            }
        }
        return ans;
        
    }
};