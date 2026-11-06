class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
        int n = nums.size();

        for (int n : nums) {
            if (n <= min1) {
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            } else {
                return true;
            }
        }

        return false;
    }
};