class Solution {
    public boolean canPartition(int[] nums) {
        int target = 0;
        int n = nums.length;
        for (int i: nums) {
            target += i;
        }
        if (target % 2 == 1) {
            return false;
        }
        target /= 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            for (int j = target; j >= cur; j--) {
                dp[j] = dp[j] || dp[j - cur];
            }
        }

        return dp[target];
    }
}