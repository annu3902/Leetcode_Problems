class Solution {
public:
    void merge(vector<int> &nums, int start, int mid, int end){
        int left = start;
        int right = mid + 1;
        vector<int> temp;

        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= end){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = start; i <= end; i++){
            nums[i] = temp[i - start];
        }
        temp.empty();
    }

    void mergeSort(vector<int> &nums, int start, int end){
        // Base Case
        if(start >= end) return;

        // Processing
        int mid = (start + end) / 2;
        // nume.begin() , nums.begin() + mid
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};