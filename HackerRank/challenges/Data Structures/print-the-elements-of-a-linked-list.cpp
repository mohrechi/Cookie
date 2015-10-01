void Print(Node *head) {
    if (head == nullptr) {
      return;
    }
    cout << head->data << endl;
    Print(head->next);
}