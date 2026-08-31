class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 26> frequency{};

        for (char c: magazine) {
            frequency[c - 'a']++;
        }

        for (char c: ransomNote) {
            if (frequency[c - 'a'] == 0) {
                return false;
            }
            frequency[c - 'a']--;
        }

        return true;
    }
};