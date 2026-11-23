class Solution {
public:
    int trap(vector<int>& arr) {

        int n=arr.size();
        int lm=0,rm=0,ans=0;
        int l=0,r=n-1;
        while(l<=r){

            if( arr[l]<=arr[r]){

                  if(arr[l]>=lm)
                  lm=arr[l];
                  else
                  ans +=lm-arr[l];
                
                l++;
            }
            else{
                if(arr[r]>=rm)
                rm=arr[r];
                else
                ans +=rm-arr[r];

                r--;
            }
        }
        return ans;
    }
};