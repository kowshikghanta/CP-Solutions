class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return recursion(prices, 0, 1);
    }
    int recursion(vector<int>& prices, int idx, int canBuy) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        int buy = 0;
        int skip = recursion(prices, idx + 1, canBuy);
        int sell = 0;

        if (canBuy) {
            buy = recursion(prices, idx + 1, 0) - prices[idx];
        } else {
            sell = prices[idx] + recursion(prices, idx + 1, 1);
        }

        return dp[idx][canBuy] = max({buy, sell, skip});
    }
};