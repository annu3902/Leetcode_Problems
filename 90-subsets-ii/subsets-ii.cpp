class Solution {
public:
vector<vector<int>> helper(vector<int> &nums, int pos, set<vector<int>> &st){
        // Base Case
        if(pos == nums.size()){
            return {{}};
        }

        // Call the recursion to form all the subset for remaining elements
        vector<vector<int>> partialAns = helper(nums, pos + 1, st);
        vector<vector<int>> finalAns;
        // unordered_set<vector<int>> st; 
        finalAns = partialAns;

        // Doing my small job to add the pos element in the subset
        for(vector<int> x : partialAns){
            x.push_back(nums[pos]);
            if(st.count(x) == 0){
                st.insert(x);
                finalAns.push_back(x);
            }
        }
        return finalAns;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        return helper(nums, 0, st);
    }
};