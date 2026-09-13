class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        shifts[n - 1] %= 26;

        for (int i = n - 2; i > -1; i--) {
            shifts[i] += shifts[i + 1];
            shifts[i] %= 26;
        }

        for (int i = 0; i < n; i++) {
            s[i] = ((s[i] - 'a' + shifts[i]) % 26) + 'a';
        }

        return s;
    }
};