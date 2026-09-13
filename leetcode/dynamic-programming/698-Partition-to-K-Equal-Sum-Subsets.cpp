class Solution {
public:
    vector<int> dp;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        dp.assign(1 << n, -1);

        for (int i: nums) {
            sum += i;
        }
        
        if (sum % k != 0) {
            return false;
        }

        sum /= k;
        std::sort(nums.rbegin(), nums.rend());

        if (nums[0] > sum) {
            return false;
        }

        return isPossible(nums, 0, 0, sum, k);
                
    }

    bool isPossible(vector<int>& nums, int mask, int cur, int target, int subsetsleft) {
        if (subsetsleft == 0) {
            return true;
        }
        if (target == cur) {
            return isPossible(nums, mask, 0, target, subsetsleft - 1);
        }
        if (dp[mask] != -1) {
            return dp[mask] == 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) != 0) {
                continue;
            }
            if (cur + nums[i] > target) {
                break;
            }
            if(isPossible(nums, mask | (1 << i), cur + nums[i], target, subsetsleft)) {
                dp[mask] = 1;
                return true;
            }
        }

        dp[mask] = 0;
        return false;
    }
};