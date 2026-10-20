using vi = vector<int>;
using ll = long long;

#define pb push_back
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vi prefMax(n + 1, 0);
        vi suffMin(n + 1, INT_MAX);
        vi drop(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            drop[i + 1] = drop[i] + (nums[i] > nums[i + 1]);
        }

        drop[n] = drop[n - 1];

        ll ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                int j = i + k - 1;

                int cnt = drop[j] - drop[i];

                if (nums[j] > nums[i]) {
                    cnt++;
                }

                if (cnt > 1 || prefMax[i] > suffMin[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};