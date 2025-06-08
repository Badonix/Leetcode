class MyLinkedList {
public:
    MyLinkedList() {
        head = nullptr;        
        tail = nullptr;        
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* it = head;
        for(int i = 0; i < index; i++){
            it = it->next;
        }                
        return it->val;
    }
    
    void addAtHead(int val) {
        size++;
        Node* curr = new Node;
        curr->val = val;
        if(!head){
            head = curr;
            tail = curr;
            return;
        }        
        curr->next = head;
        head = curr;
    }
    
    void addAtTail(int val) {
        size++;
        Node* curr = new Node;
        curr->val = val;
        if(!tail){
            head = curr;
            tail = curr;
            return;
        }        
        tail->next = curr;
        tail = curr;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;        
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        size++;
        Node* curr = new Node;
        curr->val = val;
        Node* dummy = head;
        for(int i = 0; i < index - 1; i++){
            dummy = dummy->next;
        }
        Node* temp = dummy->next;
        dummy->next = curr;
        curr->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size || size == 0) return;        
        if(size == 1){
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        if(index == 0){
            head = head->next;
            size--;
            return;
        } 

        if(index == size - 1){
            Node* dummy = head;
            for(int i = 0; i < size - 2; i++){
                dummy = dummy->next;
            }
            dummy->next = nullptr;
            tail = dummy;
            size--;
            return;
        }
        Node* dummy = head;
        for(int i = 0; i < index - 1; i++){
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
        size--;
    }

private:
    struct Node{
        int val;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */