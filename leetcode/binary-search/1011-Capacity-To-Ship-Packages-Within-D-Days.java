class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int l = 0, r = 0;
        for (int w : weights) {
            l = Math.max(l, w);
            r += w;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(weights, days, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    public boolean isPossible(int[] weights, int days, int mid) {
        int ans = 1;
        int cur = 0;
        for (int i = 0; i < weights.length; i++) {
            cur += weights[i];
            if (cur > mid) {
                cur = weights[i];
                ans++;
            }
            if (ans > days) {
                return false;
            }
        }

        return true;
    }
}