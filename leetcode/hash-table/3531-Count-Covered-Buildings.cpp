using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution {
public:
    int countCoveredBuildings(int n, vvi& buildings) {
        vi minx(n + 1, INT_MAX);
        vi maxx(n + 1, 0);
        vi miny(n + 1, INT_MAX);
        vi maxy(n + 1, 0);

        for (vi& temp : buildings) {
            int x = temp[0];
            int y = temp[1];

            minx[y] = min(minx[y], x);
            maxx[y] = max(maxx[y], x);

            miny[x] = min(miny[x], y);
            maxy[x] = max(maxy[x], y);
        }

        int ans = 0;

        for (vi& temp : buildings) {
            int x = temp[0];
            int y = temp[1];

            if (minx[y] < x && x < maxx[y] &&
                miny[x] < y && y < maxy[x]) {
                ans++;
            }
        }

        return ans;
    }
};