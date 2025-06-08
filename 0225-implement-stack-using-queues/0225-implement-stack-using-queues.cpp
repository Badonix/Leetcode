class MyStack {
public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        size++;
        q.push(x);                
    }
    
    int pop() {
        for(int i = 0; i < size - 1;i++){
            int curr = q.front();
            q.pop();
            q.push(curr);
        }
        int answ = q.front();
        q.pop();
        size--;
        return answ;
    }
    
    int top() {
        for(int i = 0; i < size - 1;i++){
            int curr = q.front();
            q.pop();
            q.push(curr);
        }
        int answ = q.front();
        q.pop();
        q.push(answ);
        return answ;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    int size;
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */