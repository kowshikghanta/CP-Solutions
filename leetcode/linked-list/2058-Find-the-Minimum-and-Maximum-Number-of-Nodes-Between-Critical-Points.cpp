/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        vector<int> ans(2, -1);
        int prevcp = -1;
        int firstcp = -1;
        int max = -1;
        int min = -1;
        int l = 1;
        ListNode* cur = head -> next;

        while (cur != NULL) {
            if (cur -> next == NULL) {
                cur = NULL;
                continue;
            }
            if ((prev -> val < cur -> val && cur -> next -> val < cur -> val) || (prev -> val > cur -> val && cur -> next -> val > cur -> val)) {
                if (firstcp == -1) {
                    firstcp = l;
                }
                if (prevcp != -1) {
                    if (ans[0] == -1) {
                        ans[0] = l - prevcp;
                    } else {
                        ans[0] = std::min(ans[0], l - prevcp);
                    }

                    ans[1] = l - firstcp;
                }
                prevcp = l;
            }
            prev = cur;
            l++;
            cur = cur -> next;
        }

        return ans;
    }
};