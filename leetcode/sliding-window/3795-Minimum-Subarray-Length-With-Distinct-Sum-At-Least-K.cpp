using vi = vector<int>;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> hs;

        int n = nums.size();
        int ans = n + 1;

        int i = 0;
        long long sum = 0;

        for (int j = 0; j < n; j++) {
            hs[nums[j]]++;

            if (hs[nums[j]] == 1) {
                sum += nums[j];
            }

            while (sum >= k) {
                ans = min(j - i + 1, ans);

                hs[nums[i]]--;

                if (hs[nums[i]] == 0) {
                    sum -= nums[i];
                }

                i++;
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};
