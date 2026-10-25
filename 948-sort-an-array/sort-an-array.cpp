class Solution {
private:
    void merge(int start, int mid, int end, vector<int>& nums){
        int i = start; int j = mid+1;
        vector<int> ans;

        while(i<=mid && j<=end){
            if(nums[i] <= nums[j]){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            ans.push_back(nums[j]);
            j++;
        }

        for(int i=start; i<=end; i++){
            nums[i] = ans[i-start];
        }
        return;
    }

    void sort(int start, int end, vector<int>& nums){
        if(start == end){
            return;
        }

        int mid = (start + end)/2;
        sort(start, mid, nums);
        sort(mid+1, end, nums);
        merge(start, mid, end, nums);
        return;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        sort(0, nums.size()-1, nums);
        return nums;
    }
};