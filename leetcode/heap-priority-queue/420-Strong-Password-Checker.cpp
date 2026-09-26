class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool digit = false;
        bool capital = false;
        bool lower = false;

        vector<int> runs;

        int count = 0;
        char cur = '$';

        for (char c : password) {
            if (cur != c) {
                if (count >= 3) runs.push_back(count);
                count = 1;
                cur = c;
            } else {
                count++;
            }

            if (isdigit(c)) digit = true;
            if (isupper(c)) capital = true;
            if (islower(c)) lower = true;
        }

        if (count >= 3) runs.push_back(count);

        int to_add = (!digit) + (!capital) + (!lower);

        if (n < 6) {
            return max(6 - n, to_add);
        }

        int replace = 0;

        for (int len : runs) {
            replace += len / 3;
        }

        if (n <= 20) {
            return max(to_add, replace);
        }

        int del = n - 20;

        for (int &len : runs) {
            if (del == 0) break;

            if (len % 3 == 0) {
                int d = min(del, 1);
                len -= d;
                del -= d;
                replace -= d;
            }
        }

        for (int &len : runs) {
            if (del < 2) break;

            if (len % 3 == 1) {
                int d = min(del, 2);
                len -= d;
                del -= d;
                replace -= d / 2;
            }
        }

        for (int &len : runs) {
            if (del == 0) break;

            int d = min(del, (len / 3) * 3);
            len -= d;
            del -= d;
            replace -= d / 3;
        }

        return (n - 20) + max(to_add, replace);
    }
};