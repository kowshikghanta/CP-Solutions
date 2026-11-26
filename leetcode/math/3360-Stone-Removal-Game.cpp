class Solution {
public:
    bool canAliceWin(int n) {
        bool isAlice = true;
        int take = 10;

        while (n >= take) {
            n -= take;
            take--;
            isAlice = !isAlice;
        }

        return !isAlice;
    }
};