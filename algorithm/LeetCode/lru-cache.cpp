class LRUCache{
public:
    LRUCache(int capacity) {
        this->_capacity = capacity;
        this->_count = 0;
        head.prev = nullptr;
        head.next = &tail;
        tail.prev = &head;
        tail.next = nullptr;
    }

    int get(int key) {
        if (pointer.find(key) != pointer.end()) {
            Node *node = pointer[key];
            deleteNode(node);
            insertNode(node);
            return node->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (pointer.find(key) == pointer.end()) {
            Node *node = new Node();
            node->key = key;
            node->value = value;
            pointer[key] = node;
            insertNode(node);
            if (++_count > _capacity) {
                Node *first = head.next;
                deleteNode(first);
                pointer.erase(first->key);
                delete first;
                --_count;
            }
        } else {
            Node *node = pointer[key];
            node->value = value;
            deleteNode(node);
            insertNode(node);
        }
    }
private:
    int _capacity;
    int _count;
    struct Node {
        Node* prev;
        Node* next;
        int key;
        int value;
    } head, tail;
    map<int, Node*> pointer;
    void deleteNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertNode(Node *node) {
        node->prev = tail.prev;
        node->next = &tail;
        tail.prev->next = node;
        tail.prev = node;
    }
};
