class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head = new Node;
        tail = new Node;
        Node* home = new Node;
        home->url = homepage;
        head->next = home;
        home->prev = head;
        home->next = tail;
        tail->prev = home;
        current = home;        
    }
    
    void visit(string url) {
        Node* curr = new Node;
        curr->url = url;
        current->next = curr;
        curr->prev = current;
        curr->next = tail;
        tail->prev = curr;
        current = curr;        
    }
    
    string back(int steps) {
        for(int i = 0; i < steps; i++){
            if(current->prev == head){
                return current->url;
            }
            current = current->prev;
        } 
        return current->url;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps; i++){
            if(current->next == tail){
                return current->url;
            }
            current = current->next;
        } 
        return current->url;
        
    }

private:
    struct Node{
        string url;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    Node* current;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */