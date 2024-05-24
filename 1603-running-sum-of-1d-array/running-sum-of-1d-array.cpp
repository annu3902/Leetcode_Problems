class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int> ans(n, 0);
        for(int j=0; j<n; j++){
            for(int k=i; k<=j; k++){
                ans[j] += nums[k];
            }
        }
        return ans;
    }
};