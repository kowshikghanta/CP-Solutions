class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string s;

        while (sum > 9) {
            sum -= 9;
            s += '9';
        }

        s += std::to_string(sum);

        while (s.size() != num) {
            s += '0';
        }

        return s;
    }
};