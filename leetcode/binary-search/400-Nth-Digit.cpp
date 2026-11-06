using ll = long long;

class Solution {
public:
    int findNthDigit(int n) {
        ll p = 9;
        ll d = 1;

        while (n > p * d) {
            n -= p * d;
            p *= 10;
            d++;
        }

        ll num = pow(10, d - 1) + (n - 1) / d;
        ll idx = (n - 1) % d;

        string s = to_string(num);

        return s[idx] - '0';
    }
};