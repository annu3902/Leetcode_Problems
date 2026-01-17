class Solution {
private:
    int dfs(int index, int target, vector<int>& nums, unordered_map<string, int>& mp){
        if(index < 0){
            return target == 0;
        }

        string st = to_string(index) + " " + to_string(target);
        if(mp.count(st)) return mp[st];

        int plus = dfs(index - 1, target - nums[index], nums, mp);
        int minus = dfs(index - 1, target + nums[index], nums, mp);

        return mp[st] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> mp;
        return dfs(n-1, target, nums, mp);
    }
};