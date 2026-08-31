class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;

            int sum = a + b + carry;

            carry = sum / 10;
            sum %= 10;

            temp->val = sum;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;

            if (l1 != NULL || l2 != NULL || carry != 0) {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        return ans;
    }
};