class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int target) {
        int left = 0, right = 0, n = nums.size();
        int sum = 0, cnt = 0;
        unordered_map<int,int> mpp;
        
        for(int i =0; i<n; i++){
            sum += nums[i];

            if(sum == target){
                cnt++;
            }

            if(mpp.find(sum - target) != mpp.end()){
                cnt += mpp[sum-target];
            }

            if(mpp.count(sum)){
                mpp[sum]++;
            }

            else{
                mpp[sum] = 1;
            }
        }

        return cnt;
    }
};