class Solution {
    public boolean consecutiveSetBits(int n) {
        int prev = 0;
        int total = 0;
        while (n != 0) {
            if (prev == 1 && n % 2 == 1) {
                total++;
            }
            if (total == 2) {
                return false;
            }
            prev = n % 2;
            n /= 2;
        }

        return total == 1;
    }
}