class Solution {
public:
    int countConsistent(vector<int>& arr) {
        int ans=0;
        int n=arr.size();

        for(int i=0; i<n; i++){
            
                int a =arr[i];
                int mn =arr[i];

            for(int j=i; j<n; j++){
                 mn=min(mn,arr[j]);
                  a &=arr[j];
                if(a==mn)ans++;
            }
        }

        return ans;
    }
};