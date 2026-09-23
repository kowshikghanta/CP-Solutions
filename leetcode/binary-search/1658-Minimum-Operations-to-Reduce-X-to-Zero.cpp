class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for (int i : nums) {
            sum += i;
        }

        if (sum < x) {
            return -1;
        }

        int target = sum - x;
        
        int i = 0;
        int ans = n + 1;
        int cur = 0;
        
        for (int j = 0; j < n; j++) {
            cur += nums[j];
            while (cur > target) {
                cur -= nums[i++];
            }
            if (cur == target) {
                ans = std::min(ans, n - (j - i + 1));
            }
        }

        return ans > n ? -1 : ans;
    }
};