class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long) k1 + k2;
        vector<long long> diff(n);

        long long l = 0;
        long long r = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            r = max(r, diff[i]);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += diff[i];
        }

        if (total <= k) {
            return 0;
        }

        while (l < r) {
            long long m = l + (r - l) / 2;
            long long need = 0;

            for (int i = 0; i < n; i++) {
                if (diff[i] > m) {
                    need += diff[i] - m;
                }
            }

            if (need <= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > l) {
                k -= diff[i] - l;
                diff[i] = l;
            }
            ans += diff[i] * diff[i];
        }

        sort(diff.rbegin(), diff.rend());

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] > 0) {
                ans -= diff[i] * diff[i];
                diff[i]--;
                ans += diff[i] * diff[i];
                k--;
            }
        }

        return ans;
    }
};