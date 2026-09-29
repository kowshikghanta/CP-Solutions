class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> dp;
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));
        if ((m + n) % 2 == 0) {
            return false;
        }
        return recursion(grid, 0, 0, 0);
    }

    bool recursion(vector<vector<char>>& grid, int i, int j, int bal) {
        bal += ((grid[i][j] == '(') ? 1 : -1);
        if (bal < 0) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return bal == 0;
        }
        if (dp[i][j][bal] != -1) {
            return dp[i][j][bal] == 1;
        }
        bool down = false;
        bool right = false;
        if (i + 1 < m) {
            down = recursion(grid, i + 1, j, bal);
        }
        if (j + 1 < n) {
            right = recursion(grid, i, j + 1, bal);
        }

        if (down || right) {
            dp[i][j][bal] = 1;
        } else {
            dp[i][j][bal] = 0;
        }

        return down || right;
    }
};