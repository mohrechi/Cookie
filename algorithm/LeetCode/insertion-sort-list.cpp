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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* insert = head;
        while (insert->next != nullptr) {
            ListNode* node = head;
            if (node->val >= insert->next->val) {
                node = insert->next->next;
                insert->next->next = head;
                head = insert->next;
                insert->next = node;
            } else {
                while (node->next->val < insert->next->val) {
                    node = node->next;
                }
                if (node != insert) {
                    ListNode *temp = insert->next;
                    insert->next = temp->next;
                    temp->next = node->next;
                    node->next = temp;
                } else {
                    insert = insert->next;
                }
            }
        }
        return head;
    }
};
