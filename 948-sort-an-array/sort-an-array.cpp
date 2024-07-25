class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        dfs(0, n-1, nums);
        return nums;
    }

    void dfs(int start, int end, vector<int>& nums){
        if(start >= end){
            return;
        }

        int mid = (start + end)/2;
        dfs(start, mid, nums);
        dfs(mid+1, end, nums);
        merge(start, mid, end, nums);
    }

    void merge(int start, int mid, int end, vector<int>& nums){
        int i = start;
        int j = mid+1;
        vector<int> temp;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else if(nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=start; i<=end; i++){
            nums[i] = temp[i-start];
        }

    }
};