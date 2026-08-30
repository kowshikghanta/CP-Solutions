class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = -1;
        int max_idx = -1;
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();

        for (int i = 0; i < n; i++) {
            if (min > nums[i]) {
                min = nums[i];
                min_idx = i;
            }
            if (max < nums[i]) {
                max = nums[i];
                max_idx = i;
            }
        }

        int left = std::min(max_idx, min_idx);
        int right = std::max(max_idx, min_idx);

        return std::min({
            right + 1,
            n - left,
            left + 1 + n - right
        });
    }
};