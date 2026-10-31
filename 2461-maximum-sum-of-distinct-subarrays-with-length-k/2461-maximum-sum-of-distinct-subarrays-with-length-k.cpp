class Solution {
    #define ll long long
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
       unordered_set<int> st;
       ll ans=0,sum=0,j=0;
       for(int i=0; i<n; i++){
        //check current element absent in set dublicate
        while(st.find(arr[i]) != st.end()){
       //jb tk dublicate remove j ko move kro i tk
                sum-=arr[j];
               st.erase(arr[j]);
               j++;
               
               
         }
         sum+=arr[i];
         st.insert(arr[i]);
         

        if( i-j+1==k){
            if(ans<sum)ans=sum;
            sum-=arr[j];
            st.erase(arr[j]);
            j++;
        }
       }
       return ans;
    }
};