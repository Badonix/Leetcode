class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        front = -1;
        rear = -1;
        data = new int[capacity];
    }

    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            data[0] = value;
            front = 0;
            rear = 0;
            size++;
            return true;
        }
        size++;
        int indexToPlace = (front-1)% capacity;
        if(front == 0){
            indexToPlace = capacity - 1;
        }
        data[indexToPlace] = value;
        front = indexToPlace;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            data[0] = value;
            front = 0;
            rear = 0;
            size++;
            return true;
        }
        size++;
        int indexToPlace = (rear + 1) % capacity;
        data[indexToPlace] = value;
        rear = indexToPlace;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;
        if(size == 1){
            size--;
            front = -1;
            rear = -1;
            return true;
        }
        size--;
        front = (front + 1)%capacity;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) return false;
        if(size == 1){
            front = -1;
            rear = -1;
            size--;
            return true;
        }
        size--;
        if(rear == 0){
            rear = size - 1;
        }else{
            rear--;
        }
        return true;
    }

    int getFront() { return front == -1 ? front : data[front]; }

    int getRear() { return rear == -1 ? rear : data[rear]; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }

private:
    int front;
    int rear;
    int* data;
    int size;
    int capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */