class Solution {
public:

    vector<vector<int>> helper(vector<int>& nums, int i, set <vector<int>> st){
        vector<vector<int>> finalans;
        sort(nums.begin(), nums.end());

        // Writting the Base Condition - 1
        if(i == nums.size()){
            return {{}};
        }

        // Ask recursion to produce the powerset for remaining (i+1) elements - 2
        
        vector<vector<int>> partialans  = helper(nums, i+1, st); 
        for(vector<int> x : partialans){
            // sort(x.begin(), x.end());
            if(st.find(x) == st.end()){
                st.insert(x);
                finalans.push_back(x);
            }
        }
        // Do your small task - 3
        for(vector<int> x : partialans){
            x.push_back(nums[i]);
            // sort(x.begin(), x.end());
            if(st.find(x) == st.end()){
                st.insert(x);
                finalans.push_back(x);
            }
        }

        return finalans;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        return helper(nums, 0, st);
    }
};