Node* Reverse(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (true) {
        swap(head->prev, head->next);
        if (head->prev == nullptr) {
            break;
        }
        head = head->prev;
    }
    return head;
}