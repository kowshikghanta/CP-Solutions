class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] nums2 = new int[2 * n];
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < 2 * n; i++) {
            nums2[i] = nums[i % n];
        }

        for (int i = 0; i < 2 * n; i++) {
            while (!stack.isEmpty() && nums2[stack.peek()] < nums2[i]) {
                ans[stack.pop() % n] = nums2[i]; 
            }
            stack.push(i);
        }
        
        return ans;
    }
}