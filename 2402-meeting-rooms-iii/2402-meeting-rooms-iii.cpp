class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        // {endTime, roomNumber}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        // available room numbers
        priority_queue<int, vector<int>, greater<int>> available;

        vector<int> roomUsedCount(n, 0);

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (auto &meeting : meetings) {

            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Free all rooms whose meeting has ended
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            // Room available
            if (!available.empty()) {

                int room = available.top();
                available.pop();

                roomUsedCount[room]++;
                busy.push({end, room});
            }

            // No room available
            else {

                auto [endTime, room] = busy.top();
                busy.pop();

                roomUsedCount[room]++;

                busy.push({endTime + duration, room});
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (roomUsedCount[i] > roomUsedCount[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};