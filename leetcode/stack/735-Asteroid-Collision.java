class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            boolean flag = true;
            while (!stack.isEmpty() && stack.peek() > 0 && asteroids[i] < 0) {
                if (Math.abs(asteroids[i]) > stack.peek()) {
                    stack.pop();
                } else if (Math.abs(asteroids[i]) == stack.peek()) {
                    stack.pop();
                    flag = false;
                    break;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                stack.push(asteroids[i]);
            }
        }
        int[] answer = new int[stack.size()];
        for (int i = stack.size() - 1; i > -1; i--) {
            answer[i] = stack.pop();
        }

        return answer;
    }
}