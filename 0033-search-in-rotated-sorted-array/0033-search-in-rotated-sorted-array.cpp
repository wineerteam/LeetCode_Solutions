class Solution {
    int solve(vector<int>&arr){
        int n=arr.size();
      int l=0,r=n-1;
      while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>arr[r]){
            l=mid+1;
        }
        else{
            r=mid;
        }
      }  
        return r;
    }
    int bs(int l, int r, vector<int>& arr,int tar){
        int ans=-1;
        while(l<=r){

            int mid=l+(r-l)/2;
            if(arr[mid]==tar){
            ans= mid;
            break;
            }
            else if( arr[mid]>tar)r=mid-1;
            else
             l=mid+1;
        }
        return ans;
    }
public:
    int search(vector<int>& arr, int tar) {
        
int n=arr.size();
// first we find pivot or min 
int pivot=solve(arr);
int idx=bs(0,pivot-1,arr,tar);

  if( idx !=-1)return idx;

  idx=bs(pivot,n-1,arr,tar);
  
  return idx;

    }
};