using ll = long long;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>> temp(n, vector<ll>(3, 0));

        for (int i = 0; i < n; i++) {
            temp[i][0] = sod(nums[i]);
            temp[i][1] = nums[i];
            temp[i][2] = i;
        }

        sort(temp.begin(), temp.end(), [](const vector<ll>& a, const vector<ll>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }

            return a[1] < b[1];
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || temp[i][2] == i) {
                continue;
            }

            int j = i;
            int count = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = temp[j][2];
                count++;
            }

            swaps += count - 1;
        }

        return swaps;
    }

    ll sod(int n) {
        ll ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
};