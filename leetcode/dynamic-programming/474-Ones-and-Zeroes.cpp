using ll = long long;
#define vvll vector<vector<ll>>
#define vll vector<ll>

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vvll dp(m + 1, vll(n + 1, 0));

        for (string s: strs) {
            ll o = 0;
            ll z = 0;

            for (char c: s) {
                if (c == '0') {
                    z++;
                } else {
                    o++;
                }
            }

            for (int i = m; i >= z; i--) {
                for (int j = n; j >= o; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - z][j - o]);
                }
            }
        }

        return dp[m][n];
    }
};