class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxArray(n, 0);
        int maxi = 0;

        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, nums[i]);
            maxArray[i] = maxi;
        }

        int left = 0;
        int right = 1;

        int ans = 0;

        while(right < n){
            if(nums[left] <= maxArray[right]){
                ans = max(ans, right - left);
                right++;
            }

            else{
                left++;
            }
        }
        return ans;
    }
};