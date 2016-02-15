class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenTail = nullptr;
        int flip = 0;
        while (head != nullptr) {
            if (flip == 0) {
                if (oddHead == nullptr) {
                    oddHead = head;
                    oddTail = head;
                } else {
                    oddTail->next = head;
                    oddTail = head;
                }
            } else {
                if (evenHead == nullptr) {
                    evenHead = head;
                    evenTail = head;
                } else {
                    evenTail->next = head;
                    evenTail = head;
                }
            }
            flip ^= 1;
            head = head->next;
        }
        if (oddTail != nullptr) {
            oddTail->next = evenHead;
        }
        if (evenTail != nullptr) {
            evenTail->next = nullptr;
        }
        return oddHead;
    }
};
