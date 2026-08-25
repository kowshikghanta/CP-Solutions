class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (map.contains(target - nums[i])) {
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }

        return {};
    }
};