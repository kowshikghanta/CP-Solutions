class Solution {
public:
    vector<vector<int>> dp;
    int strangePrinter(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return recursion(s, 0, n - 1);
    }
    int recursion(string& s, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return 1;
        }
        if (s[l] == s[r]) {
            return recursion(s, l + 1, r);
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int minimum = 1 + recursion(s, l + 1, r);

        for (int i = l + 1; i <= r; i++) {
            if (s[l] == s[i]) {
                minimum = min(minimum, recursion(s, l + 1, i - 1) + recursion(s, i, r));
            }
        }

        return dp[l][r] = minimum;
    }
};