class Solution {
public:
    int maxProduct(int n) {

        vector<int>a;
        int i=0;
        while(n>0){
            a.push_back(n%10);
            n/=10;
        }

        sort(a.begin(),a.end());
        int sz=a.size();
        
        return a[sz-1]*a[sz-2];
        
    }
};