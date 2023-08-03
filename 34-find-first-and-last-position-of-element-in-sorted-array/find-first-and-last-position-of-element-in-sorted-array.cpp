class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int end = upper_bound(nums.begin(),nums.end(),target)-nums.begin() -1;
            return {start,end};
        }
        else{
            return{-1,-1};
        }
    }
};