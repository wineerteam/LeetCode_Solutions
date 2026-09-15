
#define ll long long 
const ll m=1e9+7;
class Solution {
public:
    
        ll pwr(ll x,ll n){
              if( n==0) return 1;
         ll ans=1;
         while(n>0){
            if(n%2==1)
            ans=ans*x%m;
            x=(x*x)%m;
            n/=2;
         }
            return ans%m;

        }
public:
    int countGoodNumbers(long long n) {
      
     ll ans=(pwr(5,(n+1)/2)*pwr(4,n/2))%m;
     return ans;
    }
};