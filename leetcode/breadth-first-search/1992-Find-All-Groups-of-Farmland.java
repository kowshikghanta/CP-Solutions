class Solution {
    int m;
    int n;
    Queue<int[]> queue;
    boolean[][] visited;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    public int[][] findFarmland(int[][] land) {
        queue = new LinkedList<>();
        m = land.length;
        n = land[0].length;
        visited = new boolean[m][n];
        List<int[]> ans = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    int[] cur = new int[4];
                    cur[0] = i;
                    cur[1] = j;
                    helper(cur, land);
                    ans.add(cur);
                }
            }
        }

        int[][] ans1 = new int[ans.size()][];
        for (int i = 0; i < ans.size(); i++) {
            ans1[i] = ans.get(i);
        }

        return ans1;
    }

    public void helper(int[] cur, int[][] land) {
        queue.add(cur);
        visited[cur[0]][cur[1]] = true;
        while (!queue.isEmpty()) {
            int[] temp = queue.poll();
            cur[2] = temp[0];
            cur[3] = temp[1];
            for (int i = 0; i < 4; i++) {
                int nx = temp[0] + dx[i];
                int ny = temp[1] + dy[i];
                if (valid(nx, ny, land)) {
                    queue.add(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    public boolean valid(int x, int y, int[][] land) {
        return x >=0 && x < m && y >= 0 && y < n && land[x][y] == 1 && !visited[x][y];
    }
}