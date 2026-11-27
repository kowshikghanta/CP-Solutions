
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define sz(a) (ll)a.size()

class Solution {
public:
    int maximumSaleItems(vvi& items, int budget) {
        int n = sz(items);
        int mn = INT_MAX;

        vi gain(n, 1);

        f(i, 0, n) {
            mn = min(mn, items[i][1]);

            f(j, 0, n) {
                if(i != j && items[j][0] % items[i][0] == 0)
                    gain[i]++;
            }
        }

        vi dp(budget + 1, 0);

        f(i, 0, n) {
            int price = items[i][1];

            rf(b, budget, price) {
                dp[b] = max(dp[b], dp[b - price] + gain[i]);
            }
        }

        int ans = 0;

        f(b, 0, budget + 1) {
            ans = max(ans, dp[b] + (budget - (int)b) / mn);
        }

        return ans;
    }
};
