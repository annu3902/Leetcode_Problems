class Solution {
public:

    vector<vector<int>> helper(vector<int>& nums, int pos, set<vector<int>> st){

        // 
        if(pos == nums.size()){
            return {{}};
        }


        // calling recursion to produce the powerset for remaining
       vector<vector<int>> partialans = helper(nums, pos+1,st);
       vector<vector<int>> finalans;

        // Saving the ans 
       for(vector<int> x : partialans){
           if(st.find(x) == st.end()){
               st.insert(x);
               finalans.push_back(x);
           }
       }    

        // Doing my own task
       for(vector<int> x: partialans){
           x.push_back(nums[pos]);
           sort(x.begin(), x.end());

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