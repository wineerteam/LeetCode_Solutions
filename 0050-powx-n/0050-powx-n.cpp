class Solution {
    double fn(double x, long long n){
         if( n==0) return 1;
         double ans=1;
         while(n>0){
            if(n%2==1)
            ans=ans*x;
            x=x*x;
            n/=2;
         }
            return ans;
    }
public:
    double myPow(double x, int n) {

        long long N=n;

        if(n==0)return 1;
        
        if(n<0){
            return 1.0/fn(x,-N);
        }

        return fn(x,N);
        
    }
};