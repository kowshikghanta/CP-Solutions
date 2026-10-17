class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() > b.size()) {
                return true;
            } else if (a.size() < b.size()) {
                return false;
            }

            return a > b;
        });

        return nums[k - 1];
    }
};