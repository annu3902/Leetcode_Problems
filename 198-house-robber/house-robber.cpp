// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         // FORMING A TABLE AND EVALUATE

//         // vector<int> maxSumdp(n,0);
//         // maxSumdp[0]=nums[0];

//         // for(int i=1; i<n; ++i){
//         //     int pick=nums[i];
//         //     if(i>=2){
//         //         pick+=maxSumdp[i-2];
//         //     }
//         //     int skip=maxSumdp[i-1];
//         //     maxSumdp[i] = max(skip, pick);
//         // }
//         // return maxSumdp[n-1];
        
//         // SPACE OPTIMIZATION
//         int dp_1=nums[0];
//         int dp_2=INT_MAX;

//         for(int i=1; i<n; ++i){
//             int pick = nums[i];
//             if(dp_2 != INT_MAX){
//                 pick+=dp_2;
//             }
//             int skip = dp_1;
//             int ans = max(pick,skip);
//             dp_2=dp_1;
//             dp_1=ans;
//         }
//         return dp_1;
//     }
// };


class Solution{
public:
    int f(int i, vector<int>&nums, vector<int> &dp){
        int n=nums.size();
        if(i==n) return dp[n] = 0;
        if(dp[i] != -1) return dp[i];

        int skip=f(i+1, nums, dp);
        int pick=nums[i];
        if(i+2<=n-1)
        pick+=f(i+2, nums, dp);

        dp[i] = max(skip, pick);
        return dp[i];
    }

    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(0, nums, dp);
    }
};