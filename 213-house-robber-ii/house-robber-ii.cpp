class Solution {
private:
    // Space optimized solution of robbing 1
    int maxSum(vector<int> nums){
        int n=nums.size();
        if(n==1) return nums[0];
        int dp0=nums[0];
        int dp1=max(nums[0], nums[1]);

        for(int i=2; i<n; ++i){
            int skip=dp1;
            int pick=nums[i]+dp0;
            int ans = max(pick, skip);
            dp0=dp1;
            dp1=ans;
        }
        return dp1;
    }


public:
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     vector<int> maxSumdp1(n-1,0);
        
    //     maxSumdp1[0]=nums[0];
    //     for(int i=1; i<n-1; ++i){
    //         int skip=maxSumdp1[i-1];
    //         int pick=nums[i];
    //         if(i>=2) pick += maxSumdp1[i-2];
    //         maxSumdp1[i] = max(skip,pick);
    //     }
    //     // cout<<"Hii"<<endl;
    //     vector<int> maxSumdp2(n+1,0);
    //     maxSumdp2[1]=nums[1];
    //     for(int i=2; i<n; ++i){
    //         int skip=maxSumdp2[i-1];
    //         int pick=nums[i];
    //         if(i>=2) pick+=maxSumdp2[i-2];
    //         maxSumdp2[i]=max(skip, pick);
    //     }
    //     return max(maxSumdp1[n-2], maxSumdp2[n-1]);


        // Space Optimization
        int rob(vector<int>&nums){
            int n=nums.size();
            if(n<2) return nums[0];
            vector<int> skipLast(n-1);
            vector<int> skipFirst(n-1);

            for(int i=0; i<n-1; ++i){
                skipLast[i]=nums[i];
                skipFirst[i]=nums[i+1];
            }

            int max1=maxSum(skipLast);
            int max2=maxSum(skipFirst);

            return max(max1, max2);
        }
};