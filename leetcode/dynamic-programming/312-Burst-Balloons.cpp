class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp.assign(n, vector<int>(n + 1, -1));
        return recursion(nums, 1, n);
    }

    int recursion(vector<int>& nums, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return nums[l - 1] * nums[l] * nums[r + 1];
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;

        for (int i = l; i <= r; i++) {
            ans = max(ans, nums[l - 1] * nums[i] * nums[r + 1] + recursion(nums, l, i - 1) + recursion(nums, i + 1, r));
        }

        return dp[l][r] = ans;
    }
};