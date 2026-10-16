class Solution {
    using ll = long long;
    ll MOD = 1e9 + 7;
    vector<ll> sum, sq, lazy;
    int n;

    void apply(int node, int l, int r, ll x) {
        sq[node] = (sq[node] + 2 * x * sum[node] + x * x * (r - l + 1)) % MOD;
        sum[node] = (sum[node] + x * (r - l + 1)) % MOD;
        lazy[node] = (lazy[node] + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (!lazy[node] || l == r) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, ll x) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, x);
        update(node * 2 + 1, mid + 1, r, ql, qr, x);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int l = last.count(nums[i]) ? last[nums[i]] + 1 : 0;
            update(1, 0, n - 1, l, i, 1);
            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};