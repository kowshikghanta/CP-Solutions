/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::deque<TreeNode*> queue;
        vector<vector<int>> ans;
        if (root != NULL) {
            queue.push_back(root);
        }
        bool rev = false;

        while (!queue.empty()) {
            int n = queue.size();
            vector<int> temp(n, 0);
            for (int i = 0; i < n; i++) {
                TreeNode* cur = queue.front();
                queue.pop_front();
                temp[i] = cur -> val;
                if (cur -> left != NULL) {
                    queue.push_back(cur -> left);
                }
                if (cur -> right != NULL) {
                    queue.push_back(cur -> right);
                }
            }
            if (rev) {
                std::reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            rev = !rev;
        }

        return ans;
    }
};