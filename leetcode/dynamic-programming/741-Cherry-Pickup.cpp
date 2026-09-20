class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;

        if (r1 >= m || c1 >= n || r2 >= m || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == m - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries;

        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        int best = INT_MIN;

        best = max(best, solve(grid, r1 + 1, c1, r2 + 1));
        best = max(best, solve(grid, r1 + 1, c1, r2));
        best = max(best, solve(grid, r1, c1 + 1, r2 + 1));
        best = max(best, solve(grid, r1, c1 + 1, r2));

        if (best == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(m, -1)));

        int ans = solve(grid, 0, 0, 0);

        return max(0, ans);
    }
};