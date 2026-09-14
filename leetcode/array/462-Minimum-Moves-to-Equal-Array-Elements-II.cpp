class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int median = 0;
        if (n % 2 == 1) {
            median = nums[n / 2];
        } else {
            median = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        }

        int ans = 0;
        for (int i: nums) {
            ans += std::abs(i - median);
        }

        return ans;
    }
};