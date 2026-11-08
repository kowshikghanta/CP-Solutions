using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)

class Solution {
public:
    int countServers(vvi& grid) {
        ll m = sz(grid);
        ll n = sz(grid[0]);

        vi row(m, 0), col(n, 0);

        f(i, 0, m) {
            f(j, 0, n) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        ll ans = 0;

        f(i, 0, m) {
            f(j, 0, n) {
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};