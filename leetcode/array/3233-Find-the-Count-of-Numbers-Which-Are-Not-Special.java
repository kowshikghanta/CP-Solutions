class Solution {
    public int nonSpecialCount(int l, int r) {
        int left = (int)(Math.sqrt(l));
        int right = (int)(Math.sqrt(r));

        int count = 0;
        boolean[] a = new boolean[right + 1];
        Arrays.fill(a, true);
        for (int i = 2; i <= right; i++) {
            if (!a[i]) {
                continue;
            }
            if (a[i] && i * i >= l) {
                count++;
            }
            for (int j = i + i; j <= right; j += i) {
                a[j] = false;
            }
        }

        return r - l - count + 1;
    }
}