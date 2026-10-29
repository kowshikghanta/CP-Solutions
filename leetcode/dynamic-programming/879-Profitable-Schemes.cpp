
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
        dp.assign(i + 1, vvll(n + 1, vll(minProfit + 1, 0)));

        for (int j = 0; j <= n; j++) {
            dp[0][j][0] = 1;
        }

        for (int j = 1; j <= i; j++) {
            for (int g = 0; g <= n; g++) {
                for (int p = 0; p <= minProfit; p++) {
                    ll not_pick = dp[j - 1][g][p];
                    ll pick = 0;

                    if (g >= group[j - 1]) {
                        pick = dp[j - 1][g - group[j - 1]][max(0, p - profit[j - 1])];
                    }

                    dp[j][g][p] = (pick + not_pick) % mod;
                }
            }
        }

        return dp[i][n][minProfit];
    }
};
