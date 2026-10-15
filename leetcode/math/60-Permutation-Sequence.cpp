class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k--;

        string ans = "";

        while (n > 0) {
            int idx = k / factorials[n - 1];
            ans += to_string(nums[idx]);

            nums.erase(nums.begin() + idx);

            k %= factorials[n - 1];
            n--;
        }

        return ans;
    }
};