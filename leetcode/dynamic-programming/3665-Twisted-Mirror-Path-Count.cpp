using ll = long long;
#define vvll vector<vector<ll>>
#define vvvll vector<vector<vector<ll>>>

class Solution {
public:
    ll mod = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vvvll dp(m, vvll(n, vector<ll>(2, 0)));

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    if (j + 1 < n) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i][j][0] + dp[i][j][1]) % mod;
                    }

                    if (i + 1 < m) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0] + dp[i][j][1]) % mod;
                    }
                }
                else {
                    if (i + 1 < m) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0]) % mod;
                    }

                    if (j + 1 < n) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i][j][1]) % mod;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % mod;
    }
};
