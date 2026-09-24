class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (sod(nums[i]) == i) {
                return i;
            }
        }
        
        return -1;
    }

    int sod(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
};