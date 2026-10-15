class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> hm;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                hm[nums[j]]++;
                ans += hm.size() * hm.size();
            }
            hm.clear();
        }

        return ans;
    }
};