class Solution {
    bool check(long long mid,vector<int>& arr,int m,int k){
           int cnt=0;
           int sum=0;
        for(int i=0; i<arr.size(); i++){
            if( arr[i]<=mid){
                cnt++;
                if(cnt==k){
                    sum++;
                    cnt=0;
                }
            }
            else
                cnt=0;
            if( sum==m)return  true;
        }
        return false;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {

        //edges case 
       
        if( arr.size()/m<k) return -1;
        long long lo=1;
        long long hi=*max_element(arr.begin(),arr.end());
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if( check(mid,arr,m,k)){
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