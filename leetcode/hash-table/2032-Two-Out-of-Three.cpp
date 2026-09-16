class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        std::vector<int> ans;
        std::set<int> lookup;
        std::set<int> lookup2;
        std::set<int> ans1;

        for (int i = 0; i < nums1.size(); i++) {
            lookup.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (lookup.contains(nums2[i])) {
                ans1.insert(nums2[i]);
            }
            lookup2.insert(nums2[i]);
        }

        for (int i = 0; i < nums3.size(); i++) {
            if (lookup.contains(nums3[i]) || lookup2.contains(nums3[i])) {
                ans1.insert(nums3[i]);
            }
        }

        for (int i : ans1) {
            ans.push_back(i);
        }

        return ans;
    }
};