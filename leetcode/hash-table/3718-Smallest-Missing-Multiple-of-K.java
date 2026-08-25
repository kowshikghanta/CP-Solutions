class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> hs = new HashSet<>();
        for (int i: nums) {
            hs.add(i);
        }
        for (int i = k; i < 300; i += k) {
            if (!hs.contains(i)) {
                return i;
            }
        }

        return 69;
    }
}