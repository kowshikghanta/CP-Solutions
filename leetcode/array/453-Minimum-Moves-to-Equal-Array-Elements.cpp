using ll = long long;
using vi = vector<int>;

#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(all(nums));
        int ans = 0;

        f(i, 0, sz(nums)) {
            ans += nums[i] - mini;
        }

        return ans;
    }
};