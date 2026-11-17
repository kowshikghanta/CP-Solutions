
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define pb push_back
#define sz(a) (int)a.size()

class Solution {
public:
    vvi cost, dp;

    int minimumChanges(string s, int k) {
        int n = sz(s);

        cost.assign(n, vi(n, n));
        dp.assign(n + 1, vi(k + 1, n + 1));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) {
                        continue;
                    }

                    int cur = 0;

                    for (int r = 0; r < d; r++) {
                        int l = i + r;
                        int right = j - d + 1 + r;

                        while (l < right) {
                            if (s[l] != s[right]) {
                                cur++;
                            }

                            l += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], cur);
                }
            }
        }

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {
                for (int j = 0; j <= i - 2; j++) {
                    if (dp[j][parts - 1] == n + 1) {
                        continue;
                    }

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
