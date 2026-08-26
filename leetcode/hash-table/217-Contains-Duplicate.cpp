class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (set.contains(nums.at(i))) {
                return true;
            }
            set.insert(nums.at(i));
        }

        return false;
    }
};