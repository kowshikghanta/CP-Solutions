class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (int i: nums) {
            l = max(i, l);
            r += i;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, mid, k)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
    bool isPossible(vector<int> nums, int max, int k) {
        int cur = 0;
        int subarrays = 1;

        for (int i: nums) {
            if (cur + i > max) {
                cur = 0;
                subarrays += 1;
            }
            cur += i;
            if (subarrays > k) {
                return false;
            }
        }

        return true;
    }
};