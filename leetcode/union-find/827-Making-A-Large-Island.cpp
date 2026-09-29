class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> lookup;
    int n;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        visited.assign(n, vector<bool>(n, false));
        lookup.assign(n, vector<int>(n, 0));

        int id = 1;
        vector<int> islandsize(n * n + 1);
        int maximum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islandsize[id] = dfs(grid, i, j, id);
                    maximum = max(maximum, islandsize[id]);
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int cur = 1;
                    set<int> islands;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (lookup[ni][nj] != 0) {
                                islands.insert(lookup[ni][nj]);
                            }
                        }
                    }

                    for (int island : islands) {
                        cur += islandsize[island];
                    }

                    maximum = max(maximum, cur);
                }
            }
        }

        return maximum;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i >= n || j < 0 || j >= n ||
            visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = true;
        lookup[i][j] = id;

        int size = 1;

        for (int d = 0; d < 4; d++) {
            size += dfs(grid, i + dx[d], j + dy[d], id);
        }

        return size;
    }
};