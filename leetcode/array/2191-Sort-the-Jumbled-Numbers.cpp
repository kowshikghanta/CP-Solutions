using vvll = vector<vector<long>>;
using vl = vector<long>;
using vi = vector<int>;
using ll = long long;

#define pb push_back

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ll n = nums.size();
        vvll mapped(n, vl(2, 0));

        for (int i = 0; i < n; i++) {
            int cur = get_mapped(nums[i], mapping);
            mapped[i][0] = cur;
            mapped[i][1] = nums[i];
        }

        stable_sort(mapped.begin(), mapped.end(), [](const vl& a, const vl& b) {
            return a[0] < b[0];
        });

        vi ans;

        for (const vl& a: mapped) {
            ans.pb(a[1]);
        }

        return ans;
    }

    ll get_mapped(int n, vi& mapping) {
        if (n == 0) {
            return mapping[0];
        }

        vi digits;

        while (n > 0) {
            digits.pb(n % 10);
            n /= 10;
        }

        int ans = 0;

        for (int i = digits.size() - 1; i >= 0; i--) {
            ans *= 10;
            ans += mapping[digits[i]];
        }

        return ans;
    }
};