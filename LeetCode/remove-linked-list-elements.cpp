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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                if (prev == nullptr) {
                    head = head->next;
                } else {
                    prev->next = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};