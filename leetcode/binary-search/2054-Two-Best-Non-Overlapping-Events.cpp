class Solution {
public:
    int n;
    vector<vector<int>> dp;
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        dp.assign(n, vector<int>(2, -1));

        std::sort(
            events.begin(),
            events.end(),
            [] (const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        return recursion(events, 0, 0);
    }

    int recursion(vector<vector<int>>& events, int i, int total) {
        if (i >= n || total == 2) {
            return 0;
        }
        if (dp[i][total] != -1) {
            return dp[i][total];
        }
        int skip = recursion(events, i + 1, total);

        int next = std::lower_bound(
            events.begin() + i + 1,
            events.end(),
            events[i][1],
            [] (const vector<int>& event, int endTime) {
                return event[0] <= endTime;
            }
        ) - events.begin();

        int pick = events[i][2] + recursion(events, next, total + 1);

        dp[i][total] = std::max(pick, skip);
        return dp[i][total];
    }
};