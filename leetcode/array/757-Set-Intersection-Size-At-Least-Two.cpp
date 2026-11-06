using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(all(intervals), [](vi& a, vi& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }

            return a[1] < b[1];
        });

        int ans = 2;
        int first = intervals[0][1] - 1;
        int second = intervals[0][1];

        for (int i = 1; i < sz(intervals); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (l > second) {
                ans += 2;
                first = r - 1;
                second = r;
            }
            else if (l > first) {
                ans++;
                first = second;
                second = r;
            }
        }

        return ans;
    }
};