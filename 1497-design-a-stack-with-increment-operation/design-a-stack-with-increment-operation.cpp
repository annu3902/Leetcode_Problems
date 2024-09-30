class CustomStack {
private:
    vector<int>arr;
    int size = 0;
    int maxsize;
public:
    CustomStack(int maxSize) {
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(size < maxsize) {
            arr.push_back(x);
            size++;
        }
    }
    
    int pop() {
        if(size > 0) {
            int lastEl = arr.back();
            arr.pop_back();
            size--;
            return lastEl;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < size && i < k ; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */