class Solution {
    public int[] closestPrimes(int left, int right) {
        boolean[] isPrime = new boolean[right + 1];
        Arrays.fill(isPrime, true);
        int prev = -1;
        int distance = Integer.MAX_VALUE;
        int[] ans = {-1, -1};
        for (int i = 2; i <= right; i++) {
            if (!isPrime[i]) {
                continue;
            }
            if (prev != -1 && i >= left && prev >= left && i - prev < distance) {
                ans[0] = prev;
                ans[1] = i;
                distance = i - prev;
            }
            for (int j = i + i; j <= right; j += i) {
                isPrime[j] = false;
            }
            prev = i;
        }

        return ans;
    }
}