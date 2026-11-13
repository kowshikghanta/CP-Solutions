using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define sz(a) (ll)a.size()

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pii> dq;

        ll ans = 0;
        ll cost = 0;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int cur = nums[i];
            int count = 1;

            while (!dq.empty() && dq.back().first < cur) {
                auto [val, cnt] = dq.back();
                dq.pop_back();

                cost += 1LL * (cur - val) * cnt;
                count += cnt;
            }

            dq.push_back({cur, count});

            while (cost > k) {
                auto [val, cnt] = dq.front();
                dq.pop_front();

                cost -= 1LL * (val - nums[j]);
                j--;

                if (cnt > 1) {
                    dq.push_front({val, cnt - 1});
                }
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
