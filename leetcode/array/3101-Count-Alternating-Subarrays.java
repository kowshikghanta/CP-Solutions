class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int n = nums.length;
        long ans = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                dp[i] += dp[i - 1];
            }
            ans += dp[i];
        }
        return ans;
    }
}