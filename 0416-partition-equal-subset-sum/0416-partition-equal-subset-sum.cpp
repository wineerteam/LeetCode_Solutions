
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int tsum = accumulate(arr.begin(), arr.end(), 0);

        if (tsum % 2 != 0) return false;
        int target = tsum / 2;
        vector<bool>prev(target+1,false);
        vector<bool>cur(target+1,false);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            cur[0] = true;
            for (int j = 1; j <= target; j++) {
                bool ntake = prev[j];
                bool take = false;
                if (arr[i - 1] <= j)
                    take = prev[j - arr[i - 1]];
                cur[j] = take || ntake;
            }
            prev = cur;
        }
        return prev[target];
    }
};


// space ooptimization  