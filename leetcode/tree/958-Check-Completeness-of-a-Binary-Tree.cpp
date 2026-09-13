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
    bool isCompleteTree(TreeNode* root) {
        std::queue<TreeNode*> queue;
        bool nullFound = false;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            if (cur == NULL) {
                nullFound = true;
                continue;
            }
            if (nullFound) {
                return false;
            }
            queue.push(cur -> left);
            queue.push(cur -> right);
        }

        return true;
    }
};