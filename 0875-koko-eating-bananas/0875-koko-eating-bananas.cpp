class Solution {
    bool check(vector<int>&arr,int mid, int h){
        
        int ch=0;
        for(int &x:arr){
            ch +=x/mid;
            if(x%mid !=0)ch++;
        }
        return ch<=h;
    }
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int l=1;
        int r=*max_element(arr.begin(),arr.end());
        
        while(l<r){
           int mid=l+(r-l)/2;
           if( check(arr,mid,h)){
            r=mid;
           }
           else{
            l=mid+1;
           }
        }
        return l;
    }
};