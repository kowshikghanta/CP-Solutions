using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (auto it = 1; it < nums.size(); it++) {
            if (nums[it] == candidate) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                candidate = nums[it];
                count = 1;
            }
        }

        return candidate;
    }
};