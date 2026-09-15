class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int cons = 1;
            while (i != n - 1 && word[i] == word[i + 1]) {
                cons++;
                i++;
            }
            ans += cons - 1;
        }

        return ans;
    }
};