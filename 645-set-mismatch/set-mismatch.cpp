class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> :: iterator it;
        vector<int> ans;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]) ans.push_back(nums[i]);
        }

        for(int i = 1; i <= n; i++){
            it = find(nums.begin() , nums.end() , i);
            if(it == nums.end()) ans.push_back(i);
        }
        return ans;
    }
};