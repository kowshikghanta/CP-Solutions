class Solution {
    int[][] dp;
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        dp = new int[m][n];
        for (int[] i: dp) {
            Arrays.fill(i, -1);
        }
        return recursion(text1, text2, m - 1, n - 1);
    }

    public int recursion(String text1, String text2, int m, int n) {
        if (m == -1) {
            return 0;
        }
        if (n == -1) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        if (text1.charAt(m) == text2.charAt(n)) {
            return dp[m][n] = 1 + recursion(text1, text2, m - 1, n - 1);
        }
        return dp[m][n] = Math.max(recursion(text1, text2, m, n - 1), recursion(text1, text2, m - 1, n));
    }
}