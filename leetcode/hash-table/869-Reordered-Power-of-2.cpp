using ll = long long;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<ll, ll> hm1;
        ll count = 0;
        while (n != 0) {
            hm1[n % 10]++;
            n /= 10;
            count++;
        }

        for (ll i = 1; i < pow(10, count); i *= 2) {
            int temp = i;
            unordered_map<ll, ll> hm2;
            while (temp != 0) {
                hm2[temp % 10]++;
                temp /= 10;
            }

            if (hm1 == hm2) {
                return true;
            }
        }

        return false;
    }
};