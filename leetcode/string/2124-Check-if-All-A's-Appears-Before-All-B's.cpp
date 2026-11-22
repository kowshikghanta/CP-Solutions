class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool found_b = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' && found_b) {
                return false;
            }
            if (s[i] == 'b') {
                found_b = true;
            }
        }

        return true;
    }
};