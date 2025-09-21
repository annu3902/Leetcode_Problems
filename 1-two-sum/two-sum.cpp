class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

            for(int i=0; i<nums.size(); i++){

                int secondNum = target - nums[i];

                for(int j = i+1; j<nums.size(); j++){
                    if(nums[j] == secondNum){
                        return {i, j};
                    }
                }
            }

        return ans;
    }
};