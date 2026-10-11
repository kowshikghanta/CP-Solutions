
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < n; i++) {
            int v = lights[i];

            if (v > 0) {
                int l = max(0, i - v);
                int r = min(n - 1, i + v);

                diff[l]++;

                if (r + 1 < n) {
                    diff[r + 1]--;
                }
            }
        }

        int sum = 0;
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += diff[i];

            if (sum == 0) {
                cnt++;
            } else {
                ans += (cnt + 2) / 3;
                cnt = 0;
            }
        }

        ans += (cnt + 2) / 3;

        return ans;
    }
};
