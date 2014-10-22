/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers(0, l1, l2);
    }
private:
    ListNode *addTwoNumbers(int carry, ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) {
            if (carry) {
                return new ListNode(1);
            }
            return NULL;
        }
        int a = 0, b = 0;
        ListNode* nextA = NULL;
        ListNode* nextB = NULL;
        if (l1 != NULL) {
            a = l1->val;
            nextA = l1->next;
        }
        if (l2 != NULL) {
            b = l2->val;
            nextB = l2->next;
        }
        int temp = a + b + carry;
        ListNode *node = new ListNode(temp % 10);
        node->next = addTwoNumbers(temp >= 10, nextA, nextB);
        return node;
    }
};
