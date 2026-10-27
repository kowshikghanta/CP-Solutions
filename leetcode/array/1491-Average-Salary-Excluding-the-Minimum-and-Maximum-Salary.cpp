class Solution {
public:
    double average(vector<int>& salary) {
        int minimum = numeric_limits<int>::max();
        int maximum = numeric_limits<int>::min();
        int n = salary.size() - 2;
        double ans = 0;;

        for (int i: salary) {
            ans += i;
            minimum = min(minimum, i);
            maximum = max(maximum, i);
        }

        return (ans - minimum - maximum) / n;
    }
};