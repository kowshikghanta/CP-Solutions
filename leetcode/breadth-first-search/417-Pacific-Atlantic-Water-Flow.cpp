#define sz(a) a.size()
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vvb vector<vector<bool>>

class Solution {
public:
    vvi dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vvb pac, atl;
    int m, n;

    void bfs(queue<vi>& q, vvb& visited, vvi& heights) {
        while (!q.empty()) {
            vi temp = q.front();
            q.pop();

            for (vi cur : dir) {
                int x = temp[0] + cur[0];
                int y = temp[1] + cur[1];

                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
                    continue;
                }

                if (heights[x][y] < heights[temp[0]][temp[1]]) {
                    continue;
                }

                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = sz(heights);
        n = sz(heights[0]);

        pac.assign(m, vector<bool>(n, false));
        atl.assign(m, vector<bool>(n, false));

        queue<vi> q1, q2;

        for (int i = 0; i < m; i++) {
            q1.push({i, 0});
            pac[i][0] = true;

            q2.push({i, n - 1});
            atl[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            q1.push({0, j});
            pac[0][j] = true;

            q2.push({m - 1, j});
            atl[m - 1][j] = true;
        }

        bfs(q1, pac, heights);
        bfs(q2, atl, heights);

        vvi ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.pb({i, j});
                }
            }
        }

        return ans;
    }
};
