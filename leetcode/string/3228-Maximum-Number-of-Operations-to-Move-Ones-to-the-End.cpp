class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        std::vector<int> clusters;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int size = 0;
                while (i != n && s[i] == '1') {
                    size++;
                    i++;
                }
                if (i != n) {
                    clusters.push_back(size);
                }
            }
        }

        for (int i = 0; i < clusters.size(); i++) {
            ans += clusters[i];
            if (i != clusters.size() - 1) {
                clusters[i + 1] += clusters[i];
            }
        }

        return ans;
    }
};