class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;

        for(int i =0; i<nums.size(); i++){
            int difference = target - nums[i];
            if(mpp.count(difference)){
                return {mpp[difference], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};