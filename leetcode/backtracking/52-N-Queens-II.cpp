class Solution {
public:
    int totalNQueens(int n) {
        std::unordered_set<int> column;
        std::unordered_set<int> low_diagnol;
        std::unordered_set<int> high_diagnol;

        return recursion(column, low_diagnol, high_diagnol, n, 0);
    }

    int recursion(std::unordered_set<int> column, std::unordered_set<int> low_diagnol, std::unordered_set<int> high_diagnol, int n, int idx) {
        if (idx == n) {
            return 1;
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (column.contains(i) || low_diagnol.contains(idx + i) || high_diagnol.contains(idx - i)) {
                continue;
            }
            column.insert(i);
            low_diagnol.insert(idx + i);
            high_diagnol.insert(idx - i); 
            cur += recursion(column, low_diagnol, high_diagnol, n, idx + 1);
            column.erase(i);
            low_diagnol.erase(idx + i);
            high_diagnol.erase(idx - i); 
        }

        return cur;
    }
};