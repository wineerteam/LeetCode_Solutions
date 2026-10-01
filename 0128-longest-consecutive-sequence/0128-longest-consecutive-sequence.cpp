class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        if (arr.empty())
            return 0;

        unordered_set<int> st;

                for (int num : arr) {
            st.insert(num);
        }

        int ans = 0;

        for (int num : st) {

           
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int cnt = 1;

                
                while (st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};