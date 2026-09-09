class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stack = new ArrayDeque<>();
        int n = nums2.length;
        Map<Integer, Integer> hm = new HashMap<>();
        int[] ans = new int[nums1.length];
        Arrays.fill(ans, -1);

        for (int i = 0; i < n; i++) {
            while(!stack.isEmpty() && stack.peek() < nums2[i]) {
                hm.put(stack.pop(), nums2[i]);
            }
            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.length; i++) {
            if (hm.containsKey(nums1[i])) {
                ans[i] = hm.get(nums1[i]);
            }
        }

        return ans;
    }
}