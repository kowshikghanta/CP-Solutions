using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    vvi dp;
    int n;
    int minInsertions(string s) {
        n = s.size();
        int l = 0;
        int r = n - 1;
        dp.assign(n, vi(n, -1));

        return recursion(s, l, r);
    }

    int recursion(string& s, int l, int r) {
        if (l >= r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (s[l] == s[r]) {
            return dp[l][r] = recursion(s, l + 1, r - 1);
        }

        return dp[l][r] = 1 + min({recursion(s, l + 1, r), recursion(s, l, r - 1)});
    }
};