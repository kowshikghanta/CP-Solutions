class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if ((long)k * m > bloomDay.length) {
            return -1;
        }
        int l = bloomDay[0];
        int r = bloomDay[0];
        for (int i: bloomDay) {
            l = Math.min(i, l);
            r = Math.max(i, r);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    public static boolean isPossible(int[] bloomDay, int mid, int m, int k) {
        int flowers = 0;
        int bouquets = 0;
        for (int i: bloomDay) {
            if (i <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
            if (bouquets == m) {
                return true;
            }
        }

        return false;
    }
}