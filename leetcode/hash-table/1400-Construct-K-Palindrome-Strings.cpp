class Solution {
public:
    bool canConstruct(string s, int k) {
        int countodd = 0;
        int n = s.size();
        if (n < k) {
            return false;
        }
        std::unordered_map<char, int> hm;

        for (char i: s) {
            hm[i]++;
        }

        for (const auto& [key, value]: hm) {
            if (value % 2 == 1) {
                countodd++;
            }
        }

        return countodd <= k;
    }
};