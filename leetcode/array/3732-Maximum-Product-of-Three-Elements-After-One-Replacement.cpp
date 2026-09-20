class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        long long ans = 1LL;
        int k = 2;

        while (k > 0) {
            if (std::abs(nums[i]) < std::abs(nums[j])) {
                ans *= nums[j];
                j--;
            } else {
                ans *= nums[i];
                i++;
            }
            k--;
        }

        if (ans < 0) {
            ans *= (-100000);
        } else {
            ans *= 100000;
        }

        return ans;
    }
};