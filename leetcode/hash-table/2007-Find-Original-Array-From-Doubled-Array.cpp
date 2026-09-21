class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        std::vector<int> ans;
        std::unordered_map<int, int> freq;

        for (int x : changed) {
            freq[x]++;
        }

        std::sort(changed.begin(), changed.end());

        for (int x : changed) {
            if (freq[x] == 0)
                continue;

            if (x == 0) {
                if (freq[0] >= 2) {
                    ans.push_back(0);
                    freq[0] -= 2;
                }
            }
            else if (freq[2 * x] > 0) {
                ans.push_back(x);
                freq[x]--;
                freq[2 * x]--;
            }
        }

        if (ans.size() * 2 != changed.size())
            return {};

        return ans;
    }
};