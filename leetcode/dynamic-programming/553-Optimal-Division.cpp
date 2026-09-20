class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return to_string(nums[0]);
        }
        if(n == 2) {
            return to_string(nums[0]) + '/' +  to_string(nums[1]);
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (i == 1) {
                ans += "(";
            }
            ans += to_string(nums[i]);
            if (i != n - 1) {
                ans += "/";
            }
        }

        ans += ")";

        return ans;
    }
};