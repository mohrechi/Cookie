int CompareLists(Node *headA, Node* headB) {
    while (headA != nullptr || headB != nullptr) {
        if ((headA == nullptr) ^ (headB == nullptr)) {
            return 0;
        }
        if (headA->data != headB->data) {
            return 0;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return 1;
}