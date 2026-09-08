class Solution {
    int n;
    int[][][] dp;

    public int findNumberOfLIS(int[] nums) {
        n = nums.length;

        // dp[idx][previdx + 1][0] = length
        // dp[idx][previdx + 1][1] = count
        dp = new int[n][n + 1][2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return recursion(nums, 0, -1)[1];
    }

    public int[] recursion(int[] nums, int idx, int previdx) {

        if (idx == n) {
            return new int[]{0, 1};
        }

        int p = previdx + 1;

        if (dp[idx][p][0] != -1) {
            return dp[idx][p];
        }

        int[] skip = recursion(nums, idx + 1, previdx);

        int[] take = new int[]{Integer.MIN_VALUE, 0};

        if (previdx == -1 || nums[idx] > nums[previdx]) {
            int[] next = recursion(nums, idx + 1, idx);

            take = new int[]{
                next[0] + 1,
                next[1]
            };
        }

        if (take[0] > skip[0]) {
            return dp[idx][p] = take;
        }

        if (take[0] < skip[0]) {
            return dp[idx][p] = skip;
        }

        return dp[idx][p] =
            new int[]{take[0], take[1] + skip[1]};
    }
}