class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         
         int n = intervals.size();
         int cnt=0;

         sort(begin(intervals),end(intervals));
        
        int i=0, j=1;
        
        while( j<n){
            vector<int> curr=intervals[i];
            int cs=curr[0];
            int ce=curr[1];
            vector<int> next=intervals[j];
            int ns=next[0];
            int ne=next[1];
             // non overlpping  conditions
            if( ce <= ns){
                i=j;
                 j++;
            }
            else if( ce <=ne){
                 // overlapping h. to ab delete kise kre ye dekhna hoga
                 
                    j++;
                    cnt++;
                 }
                 else if( ce > ne){
                       i=j;

                       j++;
                       cnt++;
                 }
            

        }
       
       return cnt;
    }
};