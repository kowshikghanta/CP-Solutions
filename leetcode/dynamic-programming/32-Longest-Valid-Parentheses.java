class Solution {
    int[] dp;
    public int longestValidParentheses(String s) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);
        int i = 0;
        int maximum = 0;
        while (i != s.length()) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            }
            else {
                stack.pollFirst();
                if (stack.isEmpty()){
                    stack.push(i);
                }
                else {
                    maximum = Math.max((i - stack.peekFirst()), maximum);
                }
            }
            i++;
        }

        return maximum;
    }
}