class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<vector<int>> freq_map;
        unordered_map<int, int> hm;

        for (int i: arr) {
            hm[i]++;
        }

        for (const auto& [key, value]: hm) {
            vector<int> temp;
            temp.push_back(key);
            temp.push_back(value);
            freq_map.push_back(temp);
        }

        sort(freq_map.begin(), freq_map.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int unique = hm.size();
        int i = 0;
        while (k > 0) {
            if (freq_map[i][1] <= k) {
                unique--;
                k-= freq_map[i][1];
                i++;
            } else {
                break;
            }
        }

        return unique;
    }
};