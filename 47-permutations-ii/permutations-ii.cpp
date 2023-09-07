class Solution {
public:
    void permutation_generator(vector<int>& nums, int pos, vector<vector<int>>& ans){
        // Base Condition -1
        if(pos == nums.size()){
            // if(st.find(nums) == st.end()){
                ans.push_back(nums);
            // }
            return;
        }

        unordered_set<int> st;
        for(int i=pos; i<nums.size(); i++){

            // if(i != pos && (nums[i] == nums[i-1] || nums[i] == nums[pos])){
            //     continue;
            // }

            // else if(i != pos && nums[i] == nums[pos]){
            //     continue;
            // }

            if(st.count(nums[i])) continue;

            st.insert(nums[i]);
            swap(nums[i], nums[pos]);
            permutation_generator(nums, pos+1, ans);
            // Backtracking   
            swap(nums[i], nums[pos]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());
        permutation_generator(nums, 0, ans);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};