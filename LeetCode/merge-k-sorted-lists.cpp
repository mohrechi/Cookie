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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            head = mergeList(head, lists[i]);
        }
        return head;
    }
private:
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                if (prev == nullptr) {
                    prev = head1;
                    head = head1;
                } else {
                    prev->next = head1;
                    prev = head1;
                }
                head1 = head1->next;
            } else {
                if (prev == nullptr) {
                    prev = head2;
                    head = head2;
                } else {
                    prev->next = head2;
                    prev = head2;
                }
                head2 = head2->next;
            }
        }
        while (head1 != nullptr) {
            if (prev == nullptr) {
                prev = head1;
                head = head1;
            } else {
                prev->next = head1;
                prev = head1;
            }
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            if (prev == nullptr) {
                prev = head2;
                head = head2;
            } else {
                prev->next = head2;
                prev = head2;
            }
            head2 = head2->next;
        }
        return head;
    }
};
