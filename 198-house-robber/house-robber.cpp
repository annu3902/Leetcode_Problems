class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxSumdp(n,0);
        maxSumdp[0]=nums[0];

        for(int i=1; i<n; ++i){
            int pick=nums[i];
            // if(i==1) pick=max(nums[i], nums[i-1]);
            if(i>=2){
                pick+=maxSumdp[i-2];
            }
            int skip=maxSumdp[i-1];
            maxSumdp[i] = max(skip, pick);
        }
        return maxSumdp[n-1];
    }
};