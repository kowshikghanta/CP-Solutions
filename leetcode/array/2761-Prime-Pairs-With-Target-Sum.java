class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);

        for (int i = 2; i * i <= n; i++) {
            if (!prime[i]) {
                continue;
            }
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }

        for (int i = 2; i <= n / 2; i++) {
            if (prime[i] && prime[n - i]) {
                List<Integer> temp = new ArrayList<>();
                temp.add(i);
                temp.add(n - i);
                ans.add(temp);
            }
        }

        return ans;
    }
}