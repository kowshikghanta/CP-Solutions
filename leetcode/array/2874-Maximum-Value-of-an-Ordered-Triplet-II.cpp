using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix_max(n, 0);
        vector<ll> suffix_max(n, 0);
        vector<ll> num;
        for (int i: nums) {
            num.push_back(i);
        }

        prefix_max[0] = num[0];
        suffix_max[n - 1] = num[n - 1];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], num[i]);
        }

        for (int i = n - 2; i > -1; i--) {
            suffix_max[i] = max(suffix_max[i + 1], num[i]);
        }

        ll ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (prefix_max[i - 1] - num[i]) * suffix_max[i + 1]);
        }

        return ans;
    }
};