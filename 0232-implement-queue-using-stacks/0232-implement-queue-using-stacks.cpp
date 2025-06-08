class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       s2.push(x); 
    }
    
    int pop() {
        if(!s1.empty()){
            int answ = s1.top();
            s1.pop();
            return answ;
        }        
        while(!s2.empty()){
            int curr = s2.top();
            s2.pop();
            s1.push(curr);
        }
        int answ = s1.top();
        s1.pop();
        return answ;
    }
    
    int peek() {
        if(!s1.empty()){
            int answ = s1.top();
            return answ;
        }        
        while(!s2.empty()){
            int curr = s2.top();
            s2.pop();
            s1.push(curr);
        }
        int answ = s1.top();
        return answ;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();        
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */