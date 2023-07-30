class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // int curr = nums[0];
        int sum = 0;
        int maxi = INT_MIN;
        if(n == 1) return nums[0];
        for(int i =0; i<n; i++)
        {
            int curr = nums[i];
            sum += curr;
            if(sum < 0){
            maxi = max(maxi,sum);
                sum = 0;
            }else{
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};