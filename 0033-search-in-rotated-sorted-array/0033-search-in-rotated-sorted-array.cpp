class Solution {
public:
    int search(vector<int>& arr, int tar) {

        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){

            int mid=lo+(hi-lo)/2;

            if(arr[lo]<=arr[mid]){

               if(tar>=arr[lo]&& tar<=arr[mid]){
                if( arr[mid]==tar)
                return mid;

                else
                   hi=mid-1;
               }
               else
                  lo=mid+1;

            }
            else { //  
                     if( tar>=arr[mid]&& tar<=arr[hi]){
                        if( tar==arr[mid])
                        return mid;
                        else
                            lo=mid+1;
                     }
                     else
                       hi=mid-1;

            }
        }
       return -1; 
    }
};