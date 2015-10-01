int GetNode(Node *head, int positionFromTail) {
    int len = 0;
    Node* node = head;
    while (node != nullptr) {
        ++len;
        node = node->next;
    }
    len -= positionFromTail + 1;
    node = head;
    while (len--) {
        node = node->next;
    }
    return node->data;
}