using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)

class Solution {
public:
    ll minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<ll> left, right;
        ll sumL = 0, sumR = 0;

        auto add = [&](ll val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            }
            else {
                right.insert(val);
                sumR += val;
            }

            while (left.size() > right.size() + 1) {
                ll v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                ll v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        auto remove = [&](ll val) {
            if (left.find(val) != left.end()) {
                left.erase(left.find(val));
                sumL -= val;
            }
            else {
                right.erase(right.find(val));
                sumR -= val;
            }

            while (left.size() > right.size() + 1) {
                ll v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                ll v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        auto cost = [&]() -> ll {
            ll med = *left.rbegin();

            return med * (ll)left.size() - sumL
                 + sumR - med * (ll)right.size();
        };

        vll c(n - x + 1);

        f(i, 0, n) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                c[i - x + 1] = cost();
            }
        }

        vvll dp(k + 1, vll(n + 1, 1e18));

        dp[0][0] = 0;

        f(j, 0, k + 1) {
            f(i, 0, n + 1) {
                if (dp[j][i] == 1e18) {
                    continue;
                }

                if (i < n) {
                    dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
                }

                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] = min(
                        dp[j + 1][i + x],
                        dp[j][i] + c[i]
                    );
                }
            }
        }

        return dp[k][n];
    }
};