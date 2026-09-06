class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1;
        int r = Integer.MIN_VALUE;
        for (int i: piles) {
            r = Math.max(r, i);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(piles, h, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
    public boolean isPossible(int[] piles, int h, int eat) {
        int ans = 0;
        for (int i = 0; i < piles.length; i++) {
            ans += piles[i] / eat;
            if (piles[i] % eat != 0) {
                ans++;
            }
            if (ans > h) {
                return false;
            }
        }

        return true;
    }
}