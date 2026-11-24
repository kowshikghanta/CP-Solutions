using ll = long long;
using vi = vector<int>;

#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)

class Solution {
public:
    int maxLength(vi& nums) {
        ll n = sz(nums);
        ll ans = 0;

        f(i, 0, n) {
            ll prod = 1;
            ll g = 0;
            ll l = 1;

            f(j, i, n) {
                prod *= nums[j];
                g = gcd(g, (ll)nums[j]);
                l = lcm(l, (ll)nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > 25200) {
                    break;
                }
            }
        }

        return ans;
    }
};