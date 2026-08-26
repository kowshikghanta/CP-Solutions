class Solution {
public:
    int n;
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return recursion(prices, 1, 0);
    }
public:
    int recursion(vector<int>& prices, int canBuy, std::size_t idx) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        int buy = 0;
        int nothing = 0;
        int sell = 0;
        if (canBuy) {
            buy = -prices[idx] + recursion(prices, 0, idx + 1);
        } else {
            sell = prices[idx] + recursion(prices, 1, idx + 1);
        }
        nothing = recursion(prices, canBuy, idx + 1);

        return dp[idx][canBuy] = max({buy, sell, nothing});
    }
};