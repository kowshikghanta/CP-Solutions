class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::unordered_set<int> column;
        std::unordered_set<int> low_diagnol;
        std::unordered_set<int> high_diagnol;
        std::vector<string> board(n, string(n, '.'));
        std::vector<vector<string>> ans;
        recursion(column, low_diagnol, high_diagnol, n, 0, board, ans);

        return ans;
    }

    void recursion(std::unordered_set<int>& column, std::unordered_set<int>& low_diagnol, std::unordered_set<int>& high_diagnol, int n, int idx, std::vector<string>& board, std::vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (column.contains(i) || low_diagnol.contains(idx + i) || high_diagnol.contains(idx - i)) {
                continue;
            }
            column.insert(i);
            low_diagnol.insert(idx + i);
            high_diagnol.insert(idx - i);
            board[idx][i] = 'Q';
            recursion(column, low_diagnol, high_diagnol, n, idx + 1, board, ans);
            column.erase(i);
            low_diagnol.erase(idx + i);
            high_diagnol.erase(idx - i); 
            board[idx][i] = '.';
        }
    }
};