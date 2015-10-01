Node* InsertNth(Node *head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        return newNode;
    }
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* node = head;
    for (int i = 1; i < position; ++i) {
        node = node->next;
    }
    newNode->next = node->next;
    node->next = newNode;
    return head;
}