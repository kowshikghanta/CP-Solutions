class Solution {
    int n;
    int[] dp;
    public int rob(int[] nums) {
        n = nums.length;
        dp = new int[n];
        Arrays.fill(dp, -1);
        return recursion(nums, 0);
    }
    public int recursion(int[] nums, int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int rob = nums[i] + recursion(nums, i + 2);
        int dontrob = recursion(nums, i + 1);

        return dp[i] = Math.max(rob, dontrob);
    }
}