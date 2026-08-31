class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        bool* isPrime = new bool[n];
        std::fill(isPrime, isPrime + n, true);
        isPrime[0] = isPrime[1] = false;

        for (std::size_t i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }

            for (std::size_t j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }

        int ans = 0;
        for (std::size_t i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
            }
        }

        return ans;
    }
};