class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int dec = 1;
        int inc = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                inc = 1;
                dec++;
            } else if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else {
                dec = 1;
                inc = 1;
            }
            
            ans = max({dec, inc, ans});
        }

        return ans;
    }
};