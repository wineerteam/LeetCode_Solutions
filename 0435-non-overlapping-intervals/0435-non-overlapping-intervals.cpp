class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         
         int n = intervals.size();
         int cnt = 0 ;
         sort(begin(intervals),end(intervals));
         vector<int> last=intervals[0];
         int i=1;
         while( i<n){

       // no overlapping 
            if( last[1]<=intervals[i][0]){
                 last=intervals[i];
                 i++;
            }
            else if( last[1] <= intervals[i][1]){
                
                    cnt++;
                    i++;
            }
            else if(last[1] > intervals[i][1]){
                last=intervals[i];
                cnt++;
                i++;
            }
             
         }
    
     return cnt ;

    }
};