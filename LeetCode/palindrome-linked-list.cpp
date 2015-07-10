class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* tail = head;
        int len = 0;
        while (tail != nullptr) {
            tail = tail->next;
            ++len;
        }
        int mid = len / 2;
        tail = head;
        for (int i = 0; i < mid; ++i) {
            tail = tail->next;
        }
        return isPalindrome(head, tail, (len - 1) / 2);
    }
private:
    bool isPalindrome(ListNode* head, ListNode* &tail, int len) {
        if (len == 0) {
            return head->val == tail->val;
        }
        if (not isPalindrome(head->next, tail, len - 1)) {
            return false;
        }
        tail = tail->next;
        return head->val == tail->val;
    }
};
