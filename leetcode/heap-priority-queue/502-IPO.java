class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = capital.length;
        int i = 0;
        int[][] projects = new int[n][2];
        for (int j = 0; j < n; j++) {
            projects[j][0] = capital[j];
            projects[j][1] = profits[j];
        }

        Arrays.sort(projects, (a, b) -> Integer.compare(a[0], b[0]));
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        while (k != 0) {
            while (i != n && projects[i][0] <= w) {
                pq.add(projects[i][1]);
                i++;
            }
            if (pq.isEmpty()) {
                break;
            }
            w += pq.poll();
            k--;
        }

        return w;
    }
}