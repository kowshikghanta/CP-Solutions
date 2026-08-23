class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int l = 0;
        int r = 0;
        if (n % 2 == 1) {
            ans[n / 2] = 0;
            l = n / 2 - 1;
            r = n / 2 + 1;
        } else {
            l = n / 2 - 1;
            r = n / 2;
        }
        int p = 1;
        while (l > -1 && r < n) {
            ans[l--] = p;
            ans[r++] = -p;
            p += 1;
        }
        return ans;

    }
}