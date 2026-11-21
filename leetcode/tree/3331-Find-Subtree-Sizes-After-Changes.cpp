
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define pb push_back

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vvi adj(n);
        vi ans(n, 1);
        vi last(26, -1);
        vi prev(n, -1);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].pb(i);
        }

        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {
            auto [node, exit] = st.top();
            st.pop();

            int c = s[node] - 'a';

            if (!exit) {
                prev[node] = last[c];
                last[c] = node;

                st.push({node, true});

                for (int child : adj[node]) {
                    st.push({child, false});
                }
            }
            else {
                last[c] = prev[node];

                int p = prev[node];

                if (p == -1) {
                    p = parent[node];
                }

                if (p != -1) {
                    ans[p] += ans[node];
                }
            }
        }

        return ans;
    }
};
