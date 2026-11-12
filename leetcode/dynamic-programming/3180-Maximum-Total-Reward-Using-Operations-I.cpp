using vi = vector<int>;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {

        sort(rewardValues.begin(), rewardValues.end());

        bitset<4001> dp;
        dp[0] = 1;

        for (int x : rewardValues) {

            bitset<4001> mask;
            for (int i = 0; i < x; i++) {
                mask[i] = 1;
            }

            dp |= (dp & mask) << x;
        }

        for (int i = 4000; i >= 0; i--) {
            if (dp[i]) return i;
        }

        return 0;
    }
};