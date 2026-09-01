class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int cur = -1;
        while (n != 0) {
            if (n % 2 == 1) {
                if (cur != -1) {
                    ans = max(ans, cur + 1);
                }
                cur = 0;
            } else if (cur != -1) {
                cur++;
            }
            n /= 2;
        }

        return ans;
    }
};