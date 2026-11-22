class Solution {
    void  pcompute(vector<int>&prime, int n){
        
        prime[0]=0;
        prime[1]=0;
        for(int i=2; i*i<=n; i++){
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i)
                prime[j]=0;
            }
        }
    }
public:
    int countPrimes(int n) {
        if( n<=2)return 0;
        int cnt=0;
        vector<int>prime(n+1,1); // fill all by one think like all true or prime
        pcompute(prime,n);
        for(int i=2; i<n; i++){
            if(prime[i])cnt++;
        }
        return cnt;
    }
};