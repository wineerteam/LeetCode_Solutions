class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {

       int lo=0;
       int hi=arr.size()-1;
       int left=-1,right=-1;
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if( arr[mid]==target){
               left=mid;
               hi=mid-1;
           }
           else if( arr[mid]>target){
               hi=mid-1;
           }
           else if( arr[mid]<target){
               lo=mid+1;
           }
           
       }
       
        lo=0,hi=arr.size()-1;
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if( arr[mid]==target){
               right=mid;
               lo=mid+1;
           }
           else if( arr[mid]>target){
               hi=mid-1;
           }
           else if( arr[mid]<target){
               lo=mid+1;
           }
       }




     vector<int>ans={left,right};
        return ans;
        
    }
};