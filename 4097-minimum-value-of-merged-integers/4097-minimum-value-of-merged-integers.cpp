class Solution {
public:
    int minMergedInteger(vector<int>& arr) {
        int n=arr.size();
        int mnans=INT_MAX;
        for(int i=1;i<n;i+=2){
            string s= to_string(arr[i-1])+to_string(arr[i]);
         int temp=stoi(s);
            mnans=min(temp,mnans);
        }
        return mnans;
        
    }
};