using ll = long long;

class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    ll ans = dfs(grid, i, j);
                    if (ans % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    ll dfs(vector<vector<int>>& grid, int x, int y) {
        visited[x][y] = true;
        ll count = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (valid(nx, ny, grid)) {
                count += dfs(grid, nx, ny);
            }
        }

        return count + grid[x][y];
    }

    bool valid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] > 0;
    }
};