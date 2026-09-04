class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 1) {
            return (n / 2) * (n / 2 + 1); // first n / 2 even numbers
        } else {
            return (n / 2) * (n / 2); // first n / 2 odd numbers
        }
    }
};
/*1 3 5 7
3 1
1 3 5 7 9
4 2
1 3 5 7 9 11
5 3 1
*/