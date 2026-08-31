class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::vector<int> frequency(26, 0);

        for (char c: s) {
            frequency[c - 'a']++;
        }

        return calculate(frequency);
    }

    bool calculate (std::vector<int> frequency) {
        int expected = 0;
        for (std::size_t i = 0; i < 26; i++) {
            if (frequency[i] == 0) {
                continue;
            }
            if (!expected) {
                expected = frequency[i];
            }
            else if (expected != frequency[i]) {
                return false;
            }
        }

        return true;
    }
};