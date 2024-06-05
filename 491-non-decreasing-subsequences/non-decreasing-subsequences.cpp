class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 1) return {};
        vector<int> temp;
        solve(nums, 0, -1, temp, ans);
        return ans;
    }

    void solve(vector<int> &nums, int currIndex, int prevIndex, vector<int> temp, vector<vector<int>> &ans){

        if(currIndex >= nums.size()){
            if(temp.size() >= 2){
                auto it = find(ans.begin(), ans.end(), temp);
                if(it == ans.end()){
                    for(auto i : temp) cout<<i<<" ";
                    cout<<endl; 
                    ans.push_back(temp);
                }
            }
            return;
        }

        // Skip
        solve(nums, currIndex+1, prevIndex, temp, ans);
        // Pick
        if(prevIndex == -1 || nums[currIndex] >= nums[prevIndex]){
            temp.push_back(nums[currIndex]);
            solve(nums, currIndex+1, currIndex, temp, ans);
        }
    }
};