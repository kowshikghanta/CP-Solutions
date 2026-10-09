class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool checkValidString(string s) {
        n = s.size();
        dp.assign(n, vector<int>(2 * n + 1, -1));
        return recursion(s, 0, 0);
    }

    bool recursion(string& s, int idx, int count) {
        if (idx == n && count == 0) {
            return true;
        } else if (idx == n || count < 0) {
            return false;
        }
        if (dp[idx][count + n] != -1) {
            return dp[idx][count + n] == 1;
        }
        bool b = false;
        if (s[idx] == '(') {
            b = recursion(s, idx + 1, count + 1);
            dp[idx][count + n] = (b ? 1 : 0);
        } else if (s[idx] == ')') {
            b = recursion(s, idx + 1, count - 1);
            dp[idx][count + n] = (b ? 1 : 0);
        } else {
            b = recursion(s, idx + 1, count + 1) || recursion(s, idx + 1, count - 1) || recursion(s, idx + 1, count);
            dp[idx][count + n] = (b ? 1 : 0);
        }

        return b;
    }
};