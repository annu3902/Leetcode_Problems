class Solution {
public:
    void solve(vector<int> & nums, int index, map<int, int> &mpp, int ans){
        int n = nums.size();
        // Base Case
        if(index == n){
            mpp[ans]++;
            return;
        }

        // Processing -> Subset Generation
        // Exclude
        solve(nums, index + 1, mpp, ans);

        // Include
        ans = ans | nums[index];
        solve(nums, index + 1, mpp, ans);

    }

    int countMaxOrSubsets(vector<int>& nums) {
        map<int, int> mpp;
        solve(nums, 0, mpp, 0);
        int maxi = 0;
        int ans = -1;

        for(pair<int, int> p : mpp){
            cout<<p.first<<" "<<p.second<<endl;
        }

        for(pair<int, int> p : mpp){
            int first = p.first;
            int second = p.second;
            if(maxi < second) {
                maxi = second;
                ans = first;
            }
        }
        return maxi;
    }
};