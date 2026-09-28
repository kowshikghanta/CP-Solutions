class Solution {
public:
    int maxDepth(string s) {
        int maximum = 0;
        int cur = 0;

        for (char i: s) {
            if (i == '(') {
                cur++;
                maximum = max(cur, maximum);
            } else if (i == ')') {
                cur--;
            }
        }

        return maximum;
    }
};