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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::priority_queue<long long> pq;
        std::queue<TreeNode*> queue;

        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();

                sum += cur -> val;

                if (cur -> left != NULL) {
                    queue.push(cur -> left);
                }
                if (cur -> right != NULL) {
                    queue.push(cur -> right);
                }

                queue.pop();
            }
            pq.push(sum);
        }

        if (pq.size() < k) {
            return -1;
        }

        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        return pq.top();
    }
};