class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        long long int maxi = nums.back();
        vector<long long> prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; ++i){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        for(int i=n-1; i>=2; i--){
            if(nums[i] < prefixSum[i-1]){
                return prefixSum[i];
            }
            else if(nums[i] > prefixSum[i-1]){
                continue;
            }
        }
        return -1;
    }
};