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
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            return;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        reverseList(slow->next, nullptr);
        slow->next->next = nullptr;
        slow->next = nullptr;
        ListNode *next;
        ListNode *head1 = head;
        ListNode *head2 = fast;
        while (head1 != nullptr || head2 != nullptr) {
            if (head1 != nullptr) {
                next = head1->next;
                head1->next = head2;
                head1 = next;
            }
            if (head2 != nullptr) {
                next = head2->next;
                head2->next = head1;
                head2 = next;
            }
        }
    }
private:
    void reverseList(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return;
        }
        ListNode *prev = head;
        ListNode *node = head->next;
        while (node != tail) {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
    }
};
