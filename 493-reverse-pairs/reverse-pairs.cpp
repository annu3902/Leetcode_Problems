class Solution {

private:
    int merge(int start, int mid, int end, vector<int>& nums){

        int count = 0;
        int j = mid+1;

        for(int i=start; i<=mid; i++){
            while(j <= end && nums[i] > (long long)2 * nums[j]){
                j++;
            }
            count += (j - (mid + 1));
        }

        j = mid + 1;
        int i = start;
        vector<int> ans;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            ans.push_back(nums[i]);
            i++;
        }

        while(j <= end){
            ans.push_back(nums[j]);
            j++;
        }

        for(int i=start; i<=end; i++){
            nums[i] = ans[i-start];
        }

        return count;
    }

    int sort(int start, int end, vector<int>& nums){
        if(start >= end){
            return 0;
        }

        int mid = (start + end)/2;
        int ans = sort(start, mid, nums) + sort(mid + 1, end, nums);
        ans += merge(start, mid, end, nums);

        return ans;        
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return sort(0, n-1, nums);
    }
};