class Solution {
    int[] dx = {0, 0, 1, -1, -1, -1, 1, 1};
    int[] dy = {1, -1, 0, 0, -1, 1, -1, 1};
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isValid(nx, ny, m, n, board)) {
                        live++;
                    }
                }
                if (live < 2 && board[i][j] == 1) {
                    board[i][j] = -1;
                } else if (live <= 3 && board[i][j] == 1) {
                    board[i][j] = 1;
                } else if (live > 3 && board[i][j] == 1) {
                    board[i][j] = -1;
                } else if (live == 3 && board[i][j] == 0) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
    public boolean isValid(int nx, int ny, int m, int n, int[][] board) {
        return nx >= 0 && nx < m && ny >=0 && ny < n && (board[nx][ny] == -1 || board[nx][ny] == 1); 
    }
}