class Solution {
public:
    int maxSubArray(vector<int>& arr) {

      // use kadan's algorithm

      int mx=INT_MIN,  sum=0;
      for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        if( sum>mx)mx=sum;
        if( sum<0)sum=0;
      }
    //   if(mx<0)mx=0;
      return mx;
        
    }
};

