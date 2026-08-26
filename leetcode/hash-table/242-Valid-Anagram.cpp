class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> hash_map;

        for (char c: s) {
            if (!hash_map.contains(c)) {
                hash_map[c] = 1;
            } else {
                hash_map[c]++;
            }
        }

        for (char c: t) {
            hash_map[c]--;
            if (hash_map[c] == 0) {
                hash_map.erase(c);
            }
        }

        return hash_map.empty();
    }
};