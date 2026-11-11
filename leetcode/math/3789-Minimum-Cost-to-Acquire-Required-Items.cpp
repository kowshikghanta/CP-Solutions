using ll = long long;

class Solution {
public:
    long long minimumCost(ll cost1, ll cost2, ll costBoth, ll need1, ll need2) {
        ll ans = 0;
        if (costBoth < cost1 + cost2) {
            ans += costBoth * min(need1, need2);
            ll p = min(need1, need2);
            need1 -= p;
            need2 -= p;
        } else {
            return need1 * cost1 + need2 * cost2;
        }

        if (need1 > 0) {
            ans += need1 * min(costBoth, cost1);
        } 
        if (need2 > 0) {
            ans += need2 * min(costBoth, cost2);
        }

        return ans;
    }
};