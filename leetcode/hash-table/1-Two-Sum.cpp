class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;

        for (std::size_t i = 0; i < nums.size(); i++) {
            if (hash_map.contains(target - nums[i])) {
                return {
                    hash_map[target - nums[i]], static_cast<int> (i)
                };
            }
            hash_map[nums[i]] = static_cast<int> (i);
        }
        
        return {};
    }
};