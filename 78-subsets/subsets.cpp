class Solution {
public:

    vector<vector<int>> helper(vector<int>& nums, int i){
        vector<vector<int>> finalans;

        // Writting the Base Condition
        if(i == nums.size()){
            return {{}};
        }

        // Ask recursion to generrate the powerset for remaining (i+1)elements
        vector<vector<int>> partialans = helper(nums, i+1);
        for(vector<int> x : partialans){
            // sort(x.begin(), x.end());
            finalans.push_back(x);
        }

        // Do my small task
        for(vector<int> x : partialans){
            x.push_back(nums[i]);
            // sort(x.begin(), x.end());
            finalans.push_back(x);
        }
        return finalans;

    }   

    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums, 0);
    }
};