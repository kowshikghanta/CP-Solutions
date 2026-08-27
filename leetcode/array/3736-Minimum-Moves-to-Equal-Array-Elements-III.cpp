class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maximum = std::ranges::max(nums);
        std::size_t n = nums.size();

        for (std::size_t i = 0; i < n; i++) {
            ans += maximum - nums[i];
        }

        return ans;
    }
};