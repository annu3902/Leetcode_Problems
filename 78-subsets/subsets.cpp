class Solution {
public:
    vector<vector<int>> helper(vector<int> &nums, int pos){

        if(pos == nums.size()){
            return {{}};
        }

        // Call Recursion to form the subsets of the rest
        vector<vector<int>> partialAns = helper(nums, pos + 1);
        vector<vector<int>> finalAns;

        finalAns = partialAns;

        // Doing my small task of forming the subset for the pos element
        for(vector<int> x: partialAns){
            x.push_back(nums[pos]);
            finalAns.push_back(x);
        }
        return finalAns;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums, 0);
    }
};