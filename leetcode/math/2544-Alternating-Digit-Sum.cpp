class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        bool add = true;
        int d = log10(n);

        while (n != 0) {
            int x = n / (int)pow(10, d);

            if (add) {
                ans += x;
            } else {
                ans -= x;
            }

            add = !add;
            n %= (int)pow(10, d);
            d--;
        }

        return ans;
    }
};