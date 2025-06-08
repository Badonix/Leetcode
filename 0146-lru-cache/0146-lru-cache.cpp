class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node;
        tail = new Node;
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        Node* node = m[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        Node* temp = tail->prev;
        tail->prev = node;
        node->next = tail;
        temp->next = node;
        node->prev = temp;
        return node->val.second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node* curr = m[key];
            curr->val = make_pair(0, 0);
            curr->val.first = key;
            curr->val.second = value;
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            curr->next = nullptr;
            curr->prev = nullptr;
            Node* temp = tail->prev;
            tail->prev = curr;
            temp->next = curr;
            curr->prev = temp;
            curr->next = tail;
            return;
        }
        if(size < cap){
            size++;
            Node* curr = new Node;
            curr->val = make_pair(0, 0);
            curr->val.first = key;
            curr->val.second = value;
            m[key] = curr;
            Node* temp = tail->prev;
            tail->prev = curr;
            temp->next = curr;
            curr->prev = temp;
            curr->next = tail;
            return;
        }        
        if (size == cap) {
            Node* lru = head->next;
            head->next = lru->next;
            lru->next->prev = head;
            m.erase(lru->val.first);
            delete lru;
            Node* curr = new Node;
            curr->val = {key, value};
            m[key] = curr;
            Node* temp = tail->prev;
            temp->next = curr;
            curr->prev = temp;
            curr->next = tail;
            tail->prev = curr;
        }

    }

private:
    struct Node{
        pair<int, int> val;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int cap;
    int size;
    unordered_map<int, Node*> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */