class Solution {
public:
    vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(amount + 1);
        std::size_t n = coins.size();
        for (std::size_t i = 0; i <= amount; i++) {
            dp[i] = vector<int>(n, -1);
        }
        return recursion(amount, 0, coins, 0, n);
    }
    int recursion(int amount, int cur, vector<int>& coins, std::size_t idx, size_t n) {
        if (cur == amount) {
            return 1;
        }
        if (cur > amount) {
            return 0;
        }
        if (dp[cur][idx] != -1) {
            return dp[cur][idx];
        }
        int ans = 0;
        for (std::size_t i = idx; i < n; i++) {
            ans += recursion(amount, cur + coins[i], coins, i, n);
        }

        return dp[cur][idx] = ans;
    }
};