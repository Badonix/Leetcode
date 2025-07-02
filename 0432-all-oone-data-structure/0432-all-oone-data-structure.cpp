class AllOne {
public:
    AllOne() {
        head = nullptr;
        tail = nullptr;
    }
    
    void inc(string key) {
        if(m.count(key) == 0){
            // If there is no element at all or the first Node-s value is more than one
            if(!head || head->val != 1){
                Node* newNode = new Node;
                newNode->val = 1;
                newNode->s.insert(key);
                newNode->next = head;
                if(head) head->prev = newNode;
                head = newNode;
                if(!tail) tail = newNode;
                m[key] = newNode;
            }else{
                // It means there already is some node with value of 1 (at head) and we just insert there 
                head->s.insert(key);
                m[key] = head;
            }
            return;
        }    
        // We are here if that key exists
        Node* currNode = m[key];
        Node* nextNode = currNode->next;
        // Erase key from currents set (We need to move that key to the next one)
        currNode->s.erase(key);

        // This happens when next node doesnt exist or its value is much greater and we need to create new node in between them
        if(!nextNode || nextNode->val != currNode->val + 1){
            // Creating Node
            Node* newNode = new Node;
            newNode->val = currNode->val + 1;
            newNode->s.insert(key);

            // We connect nodes
            newNode->next = nextNode;
            newNode->prev = currNode;
            currNode->next = newNode;

            // Next node might be null
            if(nextNode) nextNode->prev = newNode;

            // Incrementing key might cause it to become a tail
            if(nextNode == nullptr) tail = newNode;

            m[key] = newNode;
        }else{
            // It means next node is val + 1 so no need to create new node
            nextNode->s.insert(key);
            m[key] = nextNode;
        }

        // When incrementing key the node currently holding the key might become empty, so we must delete it
        if(currNode->s.empty()){
            // We can write this as a seperate method
            if(currNode->prev) currNode->prev->next = currNode->next;
            if(currNode->next) currNode->next->prev = currNode->prev;
            if(head == currNode) head = currNode->next;
            if(tail == currNode) tail = currNode->prev;
            delete currNode;
        }
    }
    
    void dec(string key) {
        if(m.count(key) == 0){
            return;
        }    
        // We find the node of that key and remove key from its set
        Node* currNode = m[key];
        currNode->s.erase(key);

        if(currNode->val == 1){
            // If its 1 and we decrease => we need to remove that from map 
            m.erase(key);
        }else{
            Node* prevNode = currNode->prev;
            // If that node doesnt have a previous or its previous is much smaller, we need to spawn a new node in between, just like in inc();
            if(!prevNode || prevNode->val != currNode->val - 1){
                // Creating new node
                Node* newNode = new Node;
                newNode->val = currNode->val - 1;
                newNode->s.insert(key);

                // Connecting nodes (same as inc();)
                newNode->next = currNode;
                newNode->prev = prevNode;
                currNode->prev = newNode;
                if(prevNode) prevNode->next = newNode;
                if(head == currNode) head = newNode;
                m[key] = newNode;
            }else{
                // It means new values node already exists, so we just insert
                prevNode->s.insert(key);
                m[key] = prevNode;
            }
        }

        // Just like inc(); we need to remove the node if it became empty;
        if(currNode->s.empty()){
            if(currNode->prev) currNode->prev->next = currNode->next;
            if(currNode->next) currNode->next->prev = currNode->prev;
            if(head == currNode) head = currNode->next;
            if(tail == currNode) tail = currNode->prev;
            delete currNode;
        }
    }
    
    string getMaxKey() {
        return tail ? *tail->s.begin() : "";
    }
    
    string getMinKey() {
        return head ? *head->s.begin() : "";
    }

private:
    struct Node{
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;
        unordered_set<string> s;
    };
    unordered_map<string, Node*> m;
    Node* head;
    Node* tail;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */