class Solution {
public:
    using ll = long long;
    bool threeFibonacciSum(int n) {
        ll a = 0;
        ll b = 1;

        while ((a + b) * 2 <= n) {
            if (n == (a + b) * 2) {
                return true;
            }

            ll temp = a;
            a = b;
            b = b + temp;
        }

        return false;
    }
};