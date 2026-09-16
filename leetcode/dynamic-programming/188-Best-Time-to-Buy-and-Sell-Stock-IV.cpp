class Solution {
public:
    vector<vector<vector<int>>> dp;
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return recursion(prices, k, 0, prices.size(), 1);
    }
    int recursion(std::vector<int>& prices, int k, int idx, int n, int canBuy) {
        if (idx == n || k == 0) {
            return 0;
        }
        if (dp[idx][k][canBuy] != -1) {
            return dp[idx][k][canBuy];
        }
        if (canBuy) {
            dp[idx][k][canBuy] = std::max(-prices[idx] + recursion(prices, k, idx + 1, n, 0),
            recursion(prices, k, idx + 1, n, 1));
            return dp[idx][k][canBuy];
        } else {
            dp[idx][k][canBuy] = std::max(prices[idx] + recursion(prices, k - 1, idx + 1, n, 1),
            recursion(prices, k, idx + 1, n, 0));
            return dp[idx][k][canBuy];
        }
    }
};