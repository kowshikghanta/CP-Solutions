class Solution {
public:
    vector<long long> dp;
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        dp.assign(m, -1);

        for (int i = 0; i < m; i++) {
            rides[i][2] = rides[i][1] - rides[i][0] + rides[i][2];
        }

        std::sort(
            rides.begin(),
            rides.end(),
            [] (const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        return recursion(rides, m, 0);
    }
    long long recursion(vector<vector<int>>& rides, int n, int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long skip = recursion(rides, n, i + 1);

        int next = std::lower_bound(
            rides.begin(),
            rides.end(),
            rides[i][1],
            [] (const vector<int>& a, const int end) {
                return a[0] < end;
            }
        ) - rides.begin();

        long long take = rides[i][2] + recursion(rides, n, next);

        dp[i] = std::max(take, skip);

        return dp[i];
    }
};