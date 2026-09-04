class Solution {
public:
    int searchInsert(vector<int>& arr, int tar) {

        int n=arr.size();
        int lo=0; 
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if( tar==arr[mid]) return mid;
            else if(tar>arr[mid]){ 
                  lo=mid+1;
                  }
            else if(tar<arr[mid]){
               hi=mid-1;
               }
               
        }   
        return hi+1; 
    }
};