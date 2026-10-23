using ll = long long;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        ll n = nums.size();
        ll ans = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        return max({ans, 0LL});
    }
};