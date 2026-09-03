class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        std::unordered_map<int, int> map;
        std::vector<int> ans;
        for (int i: nums) {
            map[i]++;
        }

        for (const auto& [key, value] : map) {
            if (value == 1 && !map.contains(key - 1) && !map.contains(key + 1)) {
                ans.push_back(key);
            }
        }

        return ans;
    }
};