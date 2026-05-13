class LRUCache {
public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = NULL;
        tail = NULL;

        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        Node* curr_node = m[key];
        remove(curr_node);
        add(curr_node);
        return curr_node->val;
    }
    
    void put(int key, int value) {
        if(m.count(key) != 0) {
            remove(m[key]);
            add(m[key]);
            m[key]->val = value;
            return;
        }
        if(size == cap){
            m.erase(head->next->key);
            remove(head->next);
            size--;
        }
        Node* new_node = new Node(key, value);
        add(new_node);
        m[key] = new_node;
        size++;
    }

private:
struct Node{
    int val, key;
    Node* next;
    Node* prev;
    Node(){
        val = 0;
        key = -1;
        next = NULL;
        prev = NULL;
    };
    Node(int k, int v){
        val = v;
        key = k;
        next = NULL;
        prev = NULL;
    };
};
unordered_map<int, Node*> m;
int size, cap;
Node* head;
Node* tail;

void remove(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void add(Node* node){
    node->next = tail;
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */