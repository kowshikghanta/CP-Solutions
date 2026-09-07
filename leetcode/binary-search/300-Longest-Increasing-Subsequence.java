class Solution {
    int[][] dp;
    int n;
    public int lengthOfLIS(int[] nums) {
        n = nums.length;
        dp = new int[n][n];
        for (int[] i: dp) {
            Arrays.fill(i, -1);
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, 1 + recursion(nums, i + 1, i));
        }
        return max;
    }
    public int recursion(int[] nums, int idx, int previdx) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx][previdx] != -1) {
            return dp[idx][previdx];
        }
        int pick = 0;
        int dontpick = recursion(nums, idx + 1, previdx);
        if (nums[previdx] < nums[idx]) {
            pick = 1 + recursion(nums, idx + 1, idx);
        }

        return dp[idx][previdx] = Math.max(pick, dontpick);
    }
}