struct Result {
    long long sum;
    vector<int> indices;
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> interval(n, vector<int>(4, 0));
        vector<vector<Result>> dp(n, vector<Result>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                dp[i][j].sum = -1;
            }
        }
        for (int i = 0; i < intervals.size(); i++) {
            interval[i][0] = intervals[i][0];
            interval[i][1] = intervals[i][1];
            interval[i][2] = intervals[i][2];
            interval[i][3] = i;
        }

        std::sort(
            interval.begin(),
            interval.end(),
            [] (const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        return recursion(interval, 0, n, 0, dp).indices;
    }

    Result recursion(vector<vector<int>>& interval, int i, int n, int count, vector<vector<Result>>& dp) {

        if (i >= n || count == 4) {
            return {0LL, {}};
        }
        if (dp[i][count].sum != -1) {
            return dp[i][count];
        }

        Result skip = recursion(interval, i + 1, n, count, dp);
        int next = std::upper_bound(
            interval.begin() + i + 1,
            interval.end(),
            interval[i][1],
            [] (int end, const vector<int>& cur) {
                return cur[0] > end;
            }
        ) - interval.begin();
        std::sort(skip.indices.begin(), skip.indices.end());

        Result take = recursion(interval, next, n, count + 1, dp);
        take.sum += interval[i][2];
        take.indices.push_back(interval[i][3]);
        std::sort(take.indices.begin(), take.indices.end());

        if (skip.sum > take.sum) {
            dp[i][count] = skip;
            return skip;
        } else if (skip.sum < take.sum) {
            dp[i][count] = take;
            return take;
        }

        if (skip.indices < take.indices) {
            dp[i][count] = skip;
            return skip;
        }
        dp[i][count] = take;
        return take;
    }
};