class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[2], b[2]);
        });
        int i = 0;
        int[] ans = new int[n];
        int j = 0;
        int[][] t = new int[n][3];
        for (i = 0; i < n; i++) {
            t[i][0] = tasks[i][0];
            t[i][1] = tasks[i][1];
            t[i][2] = i;
        }
        i = 0;
        Arrays.sort(t, (a, b) -> (Integer.compare(a[0], b[0])));
        int time = t[0][0];
        while (i < n) {
            while (i < n && t[i][0] <= time) {
                pq.add(t[i++]);
            }
            if (pq.isEmpty()) {
                time = t[i][0];
                continue;
            }
            int[] cur = pq.poll();
            ans[j++] = cur[2];
            time += cur[1];
        }

        while(!pq.isEmpty()) {
            ans[j++] = pq.poll()[2];
        }

        return ans;
    }
}