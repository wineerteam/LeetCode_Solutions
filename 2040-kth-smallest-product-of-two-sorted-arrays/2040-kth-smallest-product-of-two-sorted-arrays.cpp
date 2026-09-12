#define ll long long 
class Solution {
    public:
     bool check(ll mid, vector<int>& a, vector<int>& b, ll k) {

        ll cnt = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] > 0) {

                
                ll x = floor((long double)mid / a[i]);

                cnt += upper_bound(b.begin(), b.end(), x) - b.begin();
                
            }

            else if (a[i] < 0) {

                
                ll x = ceil((long double)mid / a[i]);

                cnt += b.end() - lower_bound(b.begin(), b.end(), x);
            }

            else {

                if (mid >= 0)
                    cnt += b.size();
            }

            if (cnt >= k)
                return true;
        }

        return false;
    }
public:
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        
        long long lo=-1e10;
        long long hi=1e10;
        long long ans=-1;
        while(lo<=hi){
            long long mid =lo+(hi-lo)/2;
            if (check(mid,a,b,k)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};