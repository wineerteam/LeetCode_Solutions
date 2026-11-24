class Solution {
    vector<vector<int>>ans;
    void twosum(vector<int>&arr,int tar,int i,int j){
        while(i<j){
            int sum=arr[i]+arr[j];
           if(sum<tar)i++;

           else if(sum>tar)j--;
           else{
             ans.push_back({-tar,arr[i],arr[j]});
             i++;
             j--;
             while(i<j && arr[i]==arr[i-1])i++;
            while(i<j && arr[j]==arr[j+1])j--;
           }
        }
        
    }
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        int n=arr.size();
        if( n<3)return {};

       ans.clear();
        //   n1+n2+n3=0
        //      n2+n3=-n1

        for(int i=0; i<n; i++){
            if(i>0 && arr[i]==arr[i-1])continue;
            int n1=arr[i];
            int tar=-n1;
            twosum(arr,tar,i+1,n-1);

        }
        return ans;
    }
};