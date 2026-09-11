class Solution {
    public int totalNumbers(int[] digits) {
        Set<Integer> hs = new HashSet<>();
        int n = digits.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || k == i || digits[k] % 2 == 1) {
                        continue;
                    }
                    int ans = digits[i] * 100;
                    ans += digits[j] * 10;
                    ans += digits[k];
                    if (ans >= 100) {
                        hs.add(ans);
                    }
                }
            }
        }

        return hs.size();
    }
}