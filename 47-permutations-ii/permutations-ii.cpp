class Solution {
public:
    void permutation_generator(vector<int>& nums, int pos, vector<vector<int>>& ans ,set<vector<int>>& st){
        // Base Condition -1
        if(pos == nums.size()){
            if(st.find(nums) == st.end()){
                st.insert(nums);
                ans.push_back(nums);
            }
            return;
        }

        for(int i=pos; i<nums.size(); i++){

            // if(i != pos && (nums[i] == nums[i-1] || nums[i] == nums[pos])){
            //     continue;
            // }

            // else if(i != pos && nums[i] == nums[pos]){
            //     continue;
            // }

            swap(nums[i], nums[pos]);
            permutation_generator(nums, pos+1, ans, st);
            // Backtracking   
            swap(nums[i], nums[pos]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());
        permutation_generator(nums, 0, ans, st);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};