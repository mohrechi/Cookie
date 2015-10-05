Node* SortedInsert(Node *head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (head == nullptr) {
        return newNode;
    }
    if (newNode->data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node* node = head;
    while (node->next != nullptr && node->next->data < data) {
        node = node->next;
    }
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next != nullptr) {
        node->next->prev = newNode;
    }
    node->next = newNode;
    return head;
}