#define ll long long
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        ll l = 0;
        ll r = n - 1;

        vector<int> ans;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                int temp = mid;
                while (temp != 0 && nums[temp - 1] == target) {
                    temp--;
                }

                while (temp != n && nums[temp] == target) {
                    ans.push_back(temp++);
                }

                break;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};