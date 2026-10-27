
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int m, n;
    vvi dp;

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();

        dp.assign(m, vi(n, -1));

        return recursion(s, p, m - 1, n - 1);
    }

    bool recursion(string& s, string& p, int x, int y) {
        if (y < 0) {
            return x < 0;
        }

        if (x < 0) {
            if (p[y] == '*') {
                return recursion(s, p, x, y - 2);
            }

            return false;
        }

        if (dp[x][y] != -1) {
            return dp[x][y] == 1;
        }

        bool b = false;

        if (s[x] == p[y] || p[y] == '.') {
            b = recursion(s, p, x - 1, y - 1);
        } else if (p[y] == '*') {
            b = recursion(s, p, x, y - 2);

            if (p[y - 1] == '.' || p[y - 1] == s[x]) {
                b = b || recursion(s, p, x - 1, y);
            }
        }

        dp[x][y] = b ? 1 : 0;
        return b;
    }
};
