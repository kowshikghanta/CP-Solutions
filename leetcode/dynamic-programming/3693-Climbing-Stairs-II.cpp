class Solution {
public:
    vector<int> dp;

    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n + 1, -1);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int ans = costs[i - 1] + 1 + dp[i - 1];

            if (i >= 2) {
                ans = min(ans, costs[i - 1] + 4 + dp[i - 2]);
            }

            if (i >= 3) {
                ans = min(ans, costs[i - 1] + 9 + dp[i - 3]);
            }

            dp[i] = ans;
        }

        return dp[n];
    }
};