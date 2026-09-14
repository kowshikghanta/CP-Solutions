class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        std::unordered_set<long long> set;
        std::priority_queue<long long> pq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string cur = s.substr(i, j - i + 1);
                long long a = std::stoll(cur);

                if (!set.contains(a) && isPrime(a)) {
                    set.insert(a);
                    pq.push(a);
                }
            }
        }
        
        for (int i = 0; i < 3 && !pq.empty(); i++) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }

    bool isPrime(long long n) {
        if (n <= 1) {
            return false;
        }

        for (int i = 2; i <= std::sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
};