class Solution {

    vector<int> leftmx(vector<int>&arr){
        int n=arr.size();
        vector<int>left(n);
       left[0]=arr[0];
       for(int i=1; i<n; i++){
       left[i]=max(left[i-1],arr[i]);
       }
       return left;
    }

    vector<int> rightmx(vector<int>&arr){
        int n=arr.size();
        vector<int>right(n);
        right[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=max(right[i+1],arr[i]);
        }
        return right;
    }
public:
    int trap(vector<int>& arr) {

    vector<int>lm=leftmx(arr);
    vector<int>rm=rightmx(arr);

    int ans=0;
    for(int i=0; i<arr.size(); i++){
        int h=min(lm[i],rm[i])-arr[i];
        ans +=h;
    }

        return ans;
        
    }
};