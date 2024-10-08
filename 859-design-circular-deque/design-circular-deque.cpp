class MyCircularDeque {
public:
    deque<int> d;
    int t,p;
    MyCircularDeque(int k) {
        t=k;p=k;
    }
    
    bool insertFront(int value) {
        if(t==0){
            return false;
        }
        t--;
        d.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(t==0){
            return false;
        }
        t--;
        d.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(t==p){
            return false;
        }
        t++;
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(t==p){
            return false;
        }
        t++;
        d.pop_back();
        return true;
    }
    
    int getFront() {
        if(t==p) return -1;
        return d.front();
    }
    
    int getRear() {
        if(t==p) return -1;
        return d.back();
    }
    
    bool isEmpty() {
        return d.empty();
    }
    
    bool isFull() {
        if(d.size()==p) return true;
        return false;
    }
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