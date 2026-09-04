class Solution {
    bool check(long long mid,vector<int>& arr,int thrd){
          
         long long cnt=0;
         for(int i=0; i<arr.size(); i++){
            cnt+=(arr[i]+mid-1)/mid;
            if( cnt>thrd) return false;
         }
         return (cnt<=thrd);
    }
public:
    int smallestDivisor(vector<int>& arr, int thrd) {

        long long lo=1;
        long long hi=*max_element(arr.begin(),arr.end());
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if( check(mid,arr,thrd)){
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