class Solution {
public:
    int ans;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = nums[0];
        int n = nums.size();
        for (std::size_t i = 0; i < n; i++) {
            target |= nums[i];
        }

        ans = 0;
        for (std::size_t i = 0; i < n; i++) {
            recursion(nums, i, nums[i], target, n);
        }

        return ans;
    }

    void recursion(vector<int>& nums, std::size_t idx, int cur, int target, int n) {
        if (cur == target) {
            ans++;
        }

        for (std::size_t i = idx + 1; i < n; i++) {
            recursion(nums, i, cur | nums[i], target, n);
        }
    }
};