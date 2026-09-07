class Solution {
    int n;
    Boolean[][] dp;
    public boolean canPartition(int[] nums) {
        n = nums.length;
        int target = 0;
        for (int i = 0; i < n; i++) {
            target += nums[i];
        }
        if (target % 2 == 1) {
            return false;
        }
        dp = new Boolean[n][target + 1];
        return recursion(nums, 0, target / 2);
    }
    public boolean recursion(int[] nums, int idx, int target) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (idx == n) {
            return false;
        }
        if (dp[idx][target] != null) {
            return dp[idx][target];
        }
        boolean pick = recursion(nums, idx + 1, target - nums[idx]);
        boolean dontpick = recursion(nums, idx + 1, target);

        return dp[idx][target] = pick || dontpick;
    }
}