class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mpp;
        // sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(pair<int, int> p: mpp){
            int first = p.first;
            int second = p.second;
            if(second > 1) ans.push_back(first);
        }

        for(int i = 1; i <= n; i++){
            if(mpp.find(i) == mpp.end()) ans.push_back(i);
        }
        return ans;
        // return{-1, -1};
    }
};