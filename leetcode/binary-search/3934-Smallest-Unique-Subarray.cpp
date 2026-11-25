using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)

class Solution {
public:
    const ll mod1 = 1e9 + 7;
    const ll mod2 = 1e9 + 9;
    const ll base = 100003;

    vll h1, h2, p1, p2;

    bool isValid(ll mid, ll n) {
        unordered_map<ull, int> mp;

        f(i, 0, n - mid + 1) {
            ll j = i + mid;

            ll x = (h1[j] - h1[i] * p1[mid] % mod1
                    + mod1) % mod1;

            ll y = (h2[j] - h2[i] * p2[mid] % mod2
                    + mod2) % mod2;

            ull hash = ((ull)x << 32) | y;

            mp[hash]++;
        }

        for (auto &[hash, count] : mp) {
            if (count == 1) return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        ll n = sz(nums);

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        f(i, 0, n) {
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = p1[i] * base % mod1;
            p2[i + 1] = p2[i] * base % mod2;
        }

        ll l = 1, r = n;
        ll ans = n;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (isValid(mid, n)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};