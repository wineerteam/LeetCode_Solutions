class Solution {
    #define ll long long
    
public:
    long long minCost(vector<int>& arr) {

        int n=arr.size();
        sort(arr.begin()+1,arr.end()-1);

        ll res=(ll)arr[0]+arr[n-1];
        
        for(int i=1; i+1<n-1; i +=2){
            ll s=(ll)arr[i]+arr[i+1];
            if(s>=0)break;
            res +=s;
        }
        return res;
    }
};