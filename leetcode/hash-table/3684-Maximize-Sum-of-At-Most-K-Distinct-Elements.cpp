class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> hs;
        vector<int> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i > -1; i--) {
            if (k == 0) {
                break;
            }
            if(!hs.contains(nums[i])) {
                hs.insert(nums[i]);
                ans.push_back(nums[i]);
                k--;
            }
        }

        return ans;
    }
};