class Solution {
    int[][] dp;
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }
        return recursion(s, t, m - 1, n - 1);
    }
    public int recursion(String s, String t, int i, int j) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0;
        int skip = recursion(s, t, i - 1, j);
        if (s.charAt(i) == t.charAt(j)) {
            take = recursion(s, t, i - 1, j - 1);
        }

        return dp[i][j] = take + skip;
    }
}