class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }else if(maxHeap.top() < num){
            minHeap.push(num);
            if(minHeap.size() > maxHeap.size()){
                int topElement = minHeap.top();
                minHeap.pop();
                maxHeap.push(topElement);
            }
        }else if(maxHeap.top() >= num){
            maxHeap.push(num);
            if(maxHeap.size() - minHeap.size() > 1){
                int topElement = maxHeap.top();
                maxHeap.pop();
                minHeap.push(topElement);
            }
        }
    }
    
    double findMedian() {
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();

        int totalSize = maxHeapSize + minHeapSize;

        if((totalSize & 1) == 0){
            return (maxHeap.top() + minHeap.top())/2.0;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */