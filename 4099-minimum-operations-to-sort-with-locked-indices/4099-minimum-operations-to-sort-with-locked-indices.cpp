class Solution {

    #define ll long long
public:
    int minOperations(vector<int>& arr, vector<int>& lock, int k) {

         int n=arr.size();
         ll nd=0;
        ll swaps=0;
        int mx=0;
        int start=0;
        
        for(int i=0; i<n ;i++){
            mx=max(mx,arr[i]);
            if(mx == i+1 ){
            int ln=i-start+1;
            if(ln>1){
                for(int j=start; j<=i; j++){
                    if(lock[j]==1)
                    nd++;
                }
            }

            for(int j=start; j<=i; j++){
                for(int x=j+1; x<=i; x++){
                    if(arr[j]>arr[x])
                    swaps++;
                }
            }
            start =i+1;
        }
    }
        if( nd>k)return -1;
        return int (swaps+nd);
    }
};