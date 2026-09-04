class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> prefix(n);
        std::vector<int> suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = std::max(prefix[i - 1], nums[i]);
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i > -1; i--) {
            suffix[i] = std::min(suffix[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] - suffix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};