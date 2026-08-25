class Solution {
    long long C(long long n, long long r){
        if( r>n) return 0;
        long long ans1=1;
        r=min(r,n-r);
        for(int i=1; i<=r; i++){
            ans1=ans1*(n-i+1)/i;
        }
        return ans1;
    }
public:
    long long distributeCandies(int n, int limit) {

        if( 3*limit<n) return 0;
    long long total=C(n+3-1,3-1);
    long long bad  =3*C(n-limit+1,3-1);
    long long add  =3*C(n-2*limit,3-1);
    

    return total-bad+add;
    }
};