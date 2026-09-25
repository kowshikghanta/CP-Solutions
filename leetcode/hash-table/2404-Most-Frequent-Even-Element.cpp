class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> hm;
        int ans = -1;

        for (int i: nums) {
            hm[i]++;
        }

        for (const auto& [key, value] : hm) {
            if (key % 2 == 0 && (ans == -1 || hm[ans] < value)) {
                ans = key;
            }
        }

        return ans;
    }
};