class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp(15, vector<int>(0, 0));
        vector<int> ans(15, 0);
        vector<vector<int>> blocks;
        blocks.push_back(nums);

        for (int i = 0; i < 15; i++) {
            int bit = 14 - i;
            bool flag = true;
            vector<vector<int>> next_blocks;
            
            for (auto& block: blocks) {
                if (!flag) {
                    next_blocks.push_back(move(block));
                    continue;
                }

                vector<int> contains_bit;
                vector<int> no_bit;

                for (int j: block) {
                    if ((1 << bit) & j) {
                        contains_bit.push_back(j);
                    } else {
                        no_bit.push_back(j);
                    }
                }

                ans[i] += contains_bit.size();
                
                if (no_bit.empty()) {
                    next_blocks.push_back(move(contains_bit));
                } else {
                    if (!contains_bit.empty()) {
                        next_blocks.push_back(move(contains_bit));
                    }
                    next_blocks.push_back(move(no_bit));
                    flag = false;
                }
            }

            blocks = move(next_blocks);
        }

        return ans;
    }
};