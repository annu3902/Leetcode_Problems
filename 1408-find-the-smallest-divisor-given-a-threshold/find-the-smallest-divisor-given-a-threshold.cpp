class Solution {
public:
    bool is_possible(vector<int> nums, int mid, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += ceil((double) nums[i]/(double) mid);
            if(sum > threshold) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(is_possible(nums, mid, threshold)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};