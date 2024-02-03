class Solution {
public:
    void solve(vector<int> &nums, int pos, vector<vector<int>> &ans){
        int endPos = nums.size();
        // Base Case
        if(pos == endPos) {
            ans.push_back(nums);
            return;
        }

        // Processing
        for(int i = pos; i < endPos; i++){
            // Bring every element from position to the frist place
            swap(nums[pos], nums[i]);
            solve(nums, pos + 1, ans);
            swap(nums[pos], nums[i]);  // Backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       sort(nums.begin(), nums.end()); // --> To return the answer in sorted order
       vector<vector<int>> ans;
       solve(nums, 0, ans); 
       return ans; 
    }
};