class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        std::unordered_set<int> hash_set;
        int x = 1;

        while (n != 0) {
            if (!hash_set.contains(x)) {
                ans += x;
                hash_set.insert(k - x);
                n--;
            }
            x++;
        }

        return ans;
    }
};