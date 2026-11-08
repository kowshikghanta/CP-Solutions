class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int shortest = n + 1;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1 && prev == -1) {
                prev = i;
            } else if (nums[i] == 1) {
                shortest = min(shortest, i - prev - 1);
                prev = i;
            }
        }

        return shortest == n + 1 || shortest >= k;
    }
};