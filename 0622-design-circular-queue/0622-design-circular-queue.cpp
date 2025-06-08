class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity = k;
        data = new int[capacity];
        size = 0;
        rearIndex = -1;
        frontIndex = -1;
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()) frontIndex = 0;
        int indexToPlace = (rearIndex + 1) % capacity;
        data[indexToPlace] = value;
        rearIndex = indexToPlace;
        size++;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        if(size == 1){
            frontIndex = -1;
            rearIndex = -1;
            size--;
            return true;
        }
        size--;
        frontIndex = (frontIndex + 1) % capacity;
        return true;
    }
    int Front() {
        if(!isEmpty())
            return data[frontIndex];
        return -1;
    }
    int Rear() {
        if(!isEmpty())
            return data[rearIndex];
        return -1;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }

private:
    int* data;
    int size;
    int capacity;
    int rearIndex;
    int frontIndex;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */