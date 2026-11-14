class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();        

        int sum = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur += nums[j];
                if (j - i + 1 < l) {
                    continue;
                }
                if (j - i + 1 > r) {
                    break;
                }

                if (cur > 0) {
                    sum = min(sum, cur);
                }
            }
        }

        return sum == numeric_limits<int>::max() ? -1 : sum;
    }
};