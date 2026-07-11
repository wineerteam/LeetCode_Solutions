class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
   int i=0;

        while( i<intervals.size()){

            // end point newIntervale ke start se chhota h. so move no scope
            if(intervals[i][1] < newInterval[0]){
                i++;
            }
            // interval ka starting bra ho gya newInterval ke end se show insert and return ans found it
        else if(intervals[i][0]>newInterval[1]){
            intervals.insert(intervals.begin()+i,newInterval);
            return intervals;
        }
        else {
                  // Overlapping h to find new Interval and erase it
                  newInterval[0]=min(newInterval[0],intervals[i][0]);
                  newInterval[1]=max(newInterval[1],intervals[i][1]);
                  intervals.erase(intervals.begin()+i);
        }
    }
        intervals.push_back(newInterval);
        return intervals;

    }
};