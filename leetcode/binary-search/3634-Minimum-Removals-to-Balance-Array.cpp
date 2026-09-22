class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int minimum = n - 1;
        while (j < n) {
            if (nums[j] <= 1LL * k * nums[i]) {
                minimum = std::min(minimum, n - (j - i + 1));
                j++;
            } else {
                i++;
            }
        }

        return minimum;
    }
};