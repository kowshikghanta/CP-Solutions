class Solution {
    public List<List<Integer>> findDisappearedNumbers(int[] nums, int lower, int upper) {
        int n = nums.length;
        Set<Integer> hs = new HashSet<>();
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            hs.add(nums[i]);
        }

        int i = lower;

        while (i <= upper) {
            if (!hs.contains(i)) {
                int low = i;
                while (i <= upper && !hs.contains(i)) {
                    i++;
                }
                ans.add(Arrays.asList(low, i - 1));
            } else {
                i++;
            }
        }

        return ans;
    }
}