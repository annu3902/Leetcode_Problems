class Solution {
public:

    bool is_possible(vector<int> &nums, int mid, int k){
        int launda = 1;
        int sum = 0;
        int n = nums.size();

        for(int i =0; i<n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                launda++;
                if(launda > k || nums[i] > mid){
                    return false;
                }
                sum = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            long long int mid = low + (high - low)/2;
            if(is_possible(nums, mid, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            } 
        }
        return low;
    }
};