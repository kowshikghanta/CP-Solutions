using vi = vector<int>;
using pii = pair<int, int>;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        set<int> available;
        priority_queue<pii, vector<pii>, greater<pii>> unavailable;

        vi count(k, 0);

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < n; i++) {
            int time = arrival[i];

            while (!unavailable.empty() && unavailable.top().first <= time) {
                available.insert(unavailable.top().second);
                unavailable.pop();
            }

            if (available.empty()) {
                continue;
            }

            int idx = i % k;

            auto it = available.lower_bound(idx);

            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            count[server]++;

            unavailable.push({time + load[i], server});

            available.erase(it);
        }

        int maximum = *max_element(count.begin(), count.end());

        vi ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maximum) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};