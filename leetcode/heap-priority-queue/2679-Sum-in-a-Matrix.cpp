class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;

        for (vector<int>& a: nums) {
            std::sort(a.begin(), a.end());
        }

        for (int i = 0; i < m; i++) {
            int maximum = -1;
            for (int j = 0; j < n; j++) {
                maximum = std::max(maximum, nums[j][i]);
            }

            ans += maximum;
        }

        return ans;
    }
};