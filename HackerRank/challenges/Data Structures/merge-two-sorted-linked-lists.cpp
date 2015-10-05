Node* MergeLists(Node *headA, Node* headB) {
    Node* head = nullptr;
    Node* node = nullptr;
    while (headA != nullptr || headB != nullptr) {
        if (headA == nullptr) {
            swap(headA, headB);
        }
        if (headB == nullptr) {
            if (head == nullptr) {
                return headA;
            }
            node->next = headA;
            break;
        }
        if (headA->data > headB->data) {
            swap(headA, headB);
        }
        if (head == nullptr) {
            head = headA;
            node = head;
        } else {
            node->next = headA;
            node = headA;
        }
        headA = headA->next;
    }
    return head;
}