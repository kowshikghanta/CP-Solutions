using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()

class Solution {
public:
    vi countServers(int n, vvi& logs, int x, vi& queries) {
        int m = queries.size();

        sort(all(logs), [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pii> q;

        for (int i = 0; i < m; i++) {
            q.pb({queries[i], i});
        }

        sort(all(q));

        vi ans(m, 0);
        vi freq(n + 1, 0);

        int l = 0, r = 0;
        int cnt = 0;

        for (auto [time, idx] : q) {
            while (r < sz(logs) && logs[r][1] <= time) {
                int server = logs[r][0];

                if (freq[server] == 0) {
                    cnt++;
                }

                freq[server]++;
                r++;
            }

            while (l < r && logs[l][1] < time - x) {
                int server = logs[l][0];

                freq[server]--;

                if (freq[server] == 0) {
                    cnt--;
                }

                l++;
            }

            ans[idx] = n - cnt;
        }

        return ans;
    }
};