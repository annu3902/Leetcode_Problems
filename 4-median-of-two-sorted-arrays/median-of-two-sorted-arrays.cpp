class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                int num = nums1[i];
                
                if(leftMaxHeap.empty()){
                    leftMaxHeap.push(num);
                }else if(leftMaxHeap.top() < num) {
                    rightMinHeap.push(num);
                    if(rightMinHeap.size() > leftMaxHeap.size()){
                        leftMaxHeap.push(rightMinHeap.top());
                        rightMinHeap.pop();
                    }
                }else if(leftMaxHeap.top() >= num){
                    leftMaxHeap.push(num);
                    if(leftMaxHeap.size() - rightMinHeap.size() > 1){
                        rightMinHeap.push(leftMaxHeap.top());
                        leftMaxHeap.pop();
                    }
                }

                i++;

            }else {
                int num = nums2[j];
                
                if(leftMaxHeap.empty()){
                    leftMaxHeap.push(num);
                }else if(leftMaxHeap.top() < num) {
                    rightMinHeap.push(num);
                    if(rightMinHeap.size() > leftMaxHeap.size()){
                        leftMaxHeap.push(rightMinHeap.top());
                        rightMinHeap.pop();
                    }
                }else if(leftMaxHeap.top() >= num){
                    leftMaxHeap.push(num);
                    if(leftMaxHeap.size() - rightMinHeap.size() > 1){
                        rightMinHeap.push(leftMaxHeap.top());
                        leftMaxHeap.pop();
                    }
                }

                j++;

            }
        }

        while(i < m){
            int num = nums1[i];
                if(leftMaxHeap.empty()){
                    leftMaxHeap.push(num);
                }else if(leftMaxHeap.top() < num) {
                    rightMinHeap.push(num);
                    if(rightMinHeap.size() > leftMaxHeap.size()){
                        leftMaxHeap.push(rightMinHeap.top());
                        rightMinHeap.pop();
                    }
                }else if(leftMaxHeap.size() - rightMinHeap.size() > 1){
                    rightMinHeap.push(leftMaxHeap.top());
                    leftMaxHeap.pop();
                }

                i++;
        }

        while(j < n){
            int num = nums2[j];
                
                if(leftMaxHeap.empty()){
                    leftMaxHeap.push(num);
                }else if(leftMaxHeap.top() < num) {
                    rightMinHeap.push(num);
                    if(rightMinHeap.size() > leftMaxHeap.size()){
                        leftMaxHeap.push(rightMinHeap.top());
                        rightMinHeap.pop();
                    }
                }else if(leftMaxHeap.size() - rightMinHeap.size() > 1){
                    rightMinHeap.push(leftMaxHeap.top());
                    leftMaxHeap.pop();
                }

                j++;
        }

        if(leftMaxHeap.size() == rightMinHeap.size()){
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }

        return leftMaxHeap.top();
    }
};