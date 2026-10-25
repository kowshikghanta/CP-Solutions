using vi = vector<int>;
using vvi = vector<vector<int>>;

#define f(x, y) for (int i = x; i < y; i++)

class Solution {
public:
    int n, m;

    void dfs(vvi& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int closedIsland(vvi& grid) {
        n = grid.size();
        m = grid[0].size();

        f(0, n) {
            dfs(grid, i, 0);
            dfs(grid, i, m - 1);
        }

        f(0, m) {
            dfs(grid, 0, i);
            dfs(grid, n - 1, i);
        }

        int ans = 0;

        f(0, n) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};