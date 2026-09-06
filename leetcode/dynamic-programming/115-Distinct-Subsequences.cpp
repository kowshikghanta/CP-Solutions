class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        std::vector<vector<int>> dp(m, vector<int>(n, -1));

        return recursion(s, t, m - 1, n - 1, dp);
    }

    int recursion(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int notake = recursion(s, t, i - 1, j, dp);
        int take = 0;
        if (s[i] == t[j]) {
            take = recursion(s, t, i - 1, j - 1, dp);
        }

        return dp[i][j] = notake + take;
    }
};