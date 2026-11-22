class Solution {
public:
    int countDominantElements(vector<int>& arr) {

        int n=arr.size();
        int cnt=0;
        if(n==1)return 1;
        if( arr[0]>=arr[1])
        cnt++;

        for(int i=1; i<n-1; i++){
            int sum=arr[i-1]+arr[i+1];

            if(2*arr[i]>=sum)cnt++;
            
        }
        if( arr[n-1]>=arr[n-2])cnt++;
        return cnt;
    }
};