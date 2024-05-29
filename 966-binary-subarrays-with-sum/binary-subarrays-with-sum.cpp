class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // vector<int> prefixSum(n,0);
        unordered_map<int, int> mpp;
        int runningSum = 0;
        int count = 0;

        for(int i = 0; i<n; i++){
            
            runningSum += nums[i];

            if(runningSum == goal) count++;

            if(mpp.count(runningSum - goal)){
                count += mpp[runningSum - goal];
            }

            mpp[runningSum]++;

        }
        return count;
    }
};