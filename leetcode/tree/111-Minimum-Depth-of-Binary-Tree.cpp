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
    int minDepth(TreeNode* root) {
        return recursion(root);
    }

    int recursion(TreeNode* cur) {
        if (cur == NULL) {
            return 0;
        }

        int left = 1 + recursion(cur -> left);
        int right = 1 + recursion(cur -> right);

        if (cur -> left == NULL) {
            return right;
        }

        if (cur -> right == NULL) {
            return left;
        }

        return std::min(left, right);
    }
};