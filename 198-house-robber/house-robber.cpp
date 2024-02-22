class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // FORMING A TABLE AND EVALUATE

        // vector<int> maxSumdp(n,0);
        // maxSumdp[0]=nums[0];

        // for(int i=1; i<n; ++i){
        //     int pick=nums[i];
        //     if(i>=2){
        //         pick+=maxSumdp[i-2];
        //     }
        //     int skip=maxSumdp[i-1];
        //     maxSumdp[i] = max(skip, pick);
        // }
        // return maxSumdp[n-1];
        
        // SPACE OPTIMIZATION
        int dp_1=nums[0];
        int dp_2=INT_MAX;

        for(int i=1; i<n; ++i){
            int pick = nums[i];
            if(dp_2 != INT_MAX){
                pick+=dp_2;
            }
            int skip = dp_1;
            int ans = max(pick,skip);
            dp_2=dp_1;
            dp_1=ans;
        }
        return dp_1;
    }
};