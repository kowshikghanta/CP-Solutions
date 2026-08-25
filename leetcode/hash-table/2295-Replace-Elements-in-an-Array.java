class Solution {
    public int[] arrayChange(int[] nums, int[][] operations) {
        Map<Integer, Integer> hm = new HashMap<>();
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            hm.put(nums[i], i);
        }

        for (int[] i: operations) {
            int s = i[0];
            int d = i[1];
            nums[hm.get(s)] = d;
            hm.put(d, hm.get(s));
            hm.remove(s);
        }

        return nums;
    }
}