class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        // int ans = 
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(maxi < nums[i]){
                maxi = nums[i];
                ans = i;
            }
        }
    return ans;
    }

};