class Solution {
    public int splitArray(int[] nums, int k) {
        int l = nums[0];
        int r = 0;
        for (int i: nums) {
            r += i;
            l = Math.max(l, i);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, k, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public boolean isPossible(int[] nums, int k, int mid) {
        int subarrays = 1;
        int cur = 0;
        for (int i: nums) {
            if (cur + i > mid) {
                cur = 0;
                subarrays++;
            }
            cur += i;
            if (subarrays > k) {
                return false;
            }
        }
        
        return true;
    }
}