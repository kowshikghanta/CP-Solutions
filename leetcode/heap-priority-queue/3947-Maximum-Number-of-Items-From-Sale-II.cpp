using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define all(a) a.begin(), a.end()
#define f(i,a,b) for(ll i=a;i<b;i++)

class Solution {
public:
    int maximumSaleItems(vvi& items, int budget) {
        int n = items.size();
        vi freq(n + 1, 0), cnt(n + 1, 0);

        for(auto &a : items)
            freq[a[0]]++;

        f(i,1,n+1) {
            if(!freq[i]) continue;

            for(int j = i; j <= n; j += i)
                cnt[i] += freq[j];

            cnt[i]--;
        }

        sort(all(items), [](vi &a, vi &b) {
            return a[1] < b[1];
        });

        ll mn = items[0][1];
        ll ans = 0, rem = budget;

        for(auto &a : items) {
            ll factor = a[0], price = a[1];

            if(price >= 2 * mn) break;

            ll take = min((ll)cnt[factor], rem / price);

            ans += 2 * take;
            rem -= take * price;
        }

        ans += rem / mn;

        return ans;
    }
};