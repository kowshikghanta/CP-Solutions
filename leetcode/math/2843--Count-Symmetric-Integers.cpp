class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string temp = std::to_string(i);

            if (temp.size() % 2 == 1) {
                continue;
            }

            if (check(temp)) {
                ans++;
            }
        }
        return ans;
    }

    bool check(string temp) {
        int n = temp.size();
        int sum = 0;

        for (int i = 0; i < n / 2; i++) {
            sum += temp[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            sum -= temp[i] - '0';
        }

        return sum == 0;
    }
};