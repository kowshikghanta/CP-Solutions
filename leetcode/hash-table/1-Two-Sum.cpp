class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            for (std::size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {
                        static_cast<int>(i), 
                        static_cast<int>(j)
                    };
                }
            }
        }

        return {};
    }
};