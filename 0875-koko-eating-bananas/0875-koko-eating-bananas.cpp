 
class Solution {
    bool check(long long x,long  long h,vector<int>& arr){
        long long sum=0;
        for(int i=0; i<arr.size(); i++){
        long long cnt=0;
               sum+=(arr[i]+x-1)/x;
               
            if( sum>h) return false;
        }
           
        return sum<=h;
    }
public:
    int minEatingSpeed(vector<int>& arr, long long h) {

        long long lo=1;
        long long hi=*max_element(arr.begin(),arr.end());

        long long ans=LLONG_MAX;
    
        while(lo<=hi){

            long long mid=lo+(hi-lo)/2;
            
            if( check(mid,h,arr)){
              if (ans>mid) ans=mid;
               hi=mid-1;
            }
            else{
                   
                    lo=mid+1;
            }
        }
        return ans;
    }
};