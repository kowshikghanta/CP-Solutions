class Solution {
    public int findNonMinOrMax(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return -1;
        }

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        return a + b + c - Math.min(a, Math.min(b, c)) - Math.max(a, Math.max(b, c));
    }
}