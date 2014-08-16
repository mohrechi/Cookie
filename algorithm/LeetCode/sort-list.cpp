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
    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }
private:
    ListNode *mergeSort(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode *slow = findCenter(head);
        ListNode *next = slow->next;
        slow->next = nullptr;
        head = mergeSort(head);
        slow = mergeSort(next);
        ListNode *prev = nullptr;
        ListNode *newHead = nullptr;
        while (head != nullptr && slow != nullptr) {
            if (head->val <= slow->val) {
                if (prev == nullptr) {
                    prev = head;
                    newHead = head;
                } else {
                    prev->next = head;
                    prev = head;
                }
                head = head->next;
            } else {
                if (prev == nullptr) {
                    prev = slow;
                    newHead = slow;
                } else {
                    prev->next = slow;
                    prev = slow;
                }
                slow = slow->next;
            }
        }
        while (head != nullptr) {
            if (prev == nullptr) {
                prev = head;
                newHead = head;
            } else {
                prev->next = head;
                prev = head;
            }
            head = head->next;
        }
        while (slow != nullptr) {
            if (prev == nullptr) {
                prev = slow;
                newHead = slow;
            } else {
                prev->next = slow;
                prev = slow;
            }
            slow = slow->next;
        }
        prev->next = nullptr;
        return newHead;
    }
    ListNode *findCenter(ListNode *head) {
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
        return slow;
    }
};
