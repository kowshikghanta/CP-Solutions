using ll = long long;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        vector<int> temp;
        bool first = true;

        for (int i : nums) {
            temp.push_back(i);
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != temp[i]) {
                if (first) {
                    ans = nums[i];
                    first = false;
                } else {
                    ans &= nums[i];
                }
            }
        }

        return ans;
    }
};