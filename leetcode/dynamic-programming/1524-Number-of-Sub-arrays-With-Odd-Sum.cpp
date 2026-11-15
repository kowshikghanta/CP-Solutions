
using ll = long long;
using vi = vector<int>;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        
        ll odd = 0;
        ll even = 1;
        ll sum = 0;
        ll ans = 0;

        for (int num : arr) {
            sum += num;

            if (sum % 2) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
