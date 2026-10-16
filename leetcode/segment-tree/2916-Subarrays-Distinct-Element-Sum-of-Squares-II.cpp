class Solution {
    #define MOD 1000000007
    using ll = long long;
    vector<ll> sum, sq, lazy;

    void apply(int node, int l, int r, ll x) {
        sq[node] = (sq[node] + 2*x*sum[node] + x*x*(r-l+1)) % MOD;
        sum[node] = (sum[node] + x*(r-l+1)) % MOD;
        lazy[node] = (lazy[node] + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (!lazy[node] || l == r) return;

        int mid = (l+r)/2;
        apply(2*node, l, mid, lazy[node]);
        apply(2*node+1, mid+1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l+r)/2;
        update(2*node, l, mid, ql, qr);
        update(2*node+1, mid+1, r, ql, qr);

        sum[node] = (sum[2*node] + sum[2*node+1]) % MOD;
        sq[node] = (sq[2*node] + sq[2*node+1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4*n, 0);
        sq.assign(4*n, 0);
        lazy.assign(4*n, 0);

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int l = last.count(nums[i]) ? last[nums[i]]+1 : 0;

            update(1, 0, n-1, l, i);
            last[nums[i]] = i;

            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};