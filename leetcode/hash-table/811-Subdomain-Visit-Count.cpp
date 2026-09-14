class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        std::unordered_map<string, int> hash_map;
        std::vector<string> ans;

        for (int i = 0; i < n; i++) {
            vector<string> keys;
            int j = 0;
            while (cpdomains[i][j] != ' ') {
                j++;
            }

            int value = std::stoi(cpdomains[i].substr(0, j));
            keys.push_back(cpdomains[i].substr(j + 1));
            j++;
            for (j ; j < cpdomains[i].size(); j++) {
                if (cpdomains[i][j] == '.') {
                    keys.push_back(cpdomains[i].substr(j + 1));
                }
            }

            for (j = 0; j < keys.size(); j++) {
                hash_map[keys[j]] += value;
            } 
        }

        for (const auto& [key, value] : hash_map) {
            ans.push_back(std::to_string(value)+' '+key);
        }

        return ans;
    }
};