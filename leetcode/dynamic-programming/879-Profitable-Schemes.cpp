#define vi vector<int>&
using ll = long long;
#define vvvll vector<vector<vector<ll>>>
#define vvll vector<vector<ll>>
#define vll vector<ll>

class Solution {
public:
    ll mod = 1e9 + 7;
    vvvll dp;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int i = group.size();
        dp.assign(i, vvll(n + 1, vll(minProfit + 1, -1)));

        return recursion(n, i - 1, minProfit, group, profit);
    }

    ll recursion(int n, int i, int minProfit, vi group, vi profit) {
        if (i < 0) {
            return minProfit <= 0;
        }

        if (dp[i][n][minProfit] != -1) {
            return dp[i][n][minProfit];
        }

        ll pick = 0;
        ll not_pick = recursion(n, i - 1, minProfit, group, profit);

        if (n >= group[i]) {
            pick = recursion(n - group[i], i - 1, max(0, minProfit - profit[i]), group, profit);
        }

        return dp[i][n][minProfit] = (pick + not_pick) % mod;
    }
};