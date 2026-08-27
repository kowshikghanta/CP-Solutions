class Solution {
public:
    const int MAX = 10001;
public:
    int coinChange(vector<int>& coins, int amount) {
        std::size_t n = coins.size();
        vector<int> dp(amount + 1, -1);
        int ans = recursion(coins, amount, 0, n, dp);
        return ans == MAX ? -1 : ans;
    }
    int recursion(vector<int>& coins, int amount, int cur, int n, vector<int>& dp) {
        if (cur == amount) {
            return 0;
        }
        if (cur > amount) {
            return MAX;
        }
        if (dp[cur] != -1) {
            return dp[cur];
        }
        int ans = MAX;

        for (int coin : coins) {
            if (coin > amount) {
                continue;
            }
            int res = recursion(coins, amount, cur + coin, n, dp);
            if (cur + coin <= amount) {
                ans = std::min(ans, res + 1);
            }
        }

        return dp[cur] = ans;
    }
};