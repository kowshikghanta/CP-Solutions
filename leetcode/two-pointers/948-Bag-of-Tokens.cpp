class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        std::sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = n - 1;
        int maximum = 0;
        int score = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                score++;
                maximum = std::max(maximum, score);
                power -= tokens[i];
                i++;
            } else if (score >= 1) {
                score--;
                maximum = std::max(maximum, score);
                power += tokens[j];
                j--;
            } else {
                break;
            }
        }

        return maximum;
    }
};