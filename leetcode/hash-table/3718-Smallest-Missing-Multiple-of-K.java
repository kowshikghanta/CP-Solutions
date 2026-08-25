class Solution {
    public int missingMultiple(int[] nums, int k) {
        int[] set = new int[201];
        for (int i: nums) {
            set[i] += 1;
        }
        for (int i = k; i < 300; i += k) {
            if (set[i] == 0) {
                return i;
            }
        }

        return 69;
    }
}