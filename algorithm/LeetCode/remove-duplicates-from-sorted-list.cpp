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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *node = head;
        while (node != nullptr) {
            ListNode *next = node->next;
            while (next != nullptr) {
                if (next->val != node->val) {
                    break;
                }
                next = next->next;
            }
            node->next = next;
            node = next;
        }
        return head;
    }
};
