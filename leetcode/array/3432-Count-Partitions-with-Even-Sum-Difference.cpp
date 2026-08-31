class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for (int i: nums) {
            total += i;
        }

        if (total % 2 == 0) {
            return n - 1;
        }
        return 0;
    }
};