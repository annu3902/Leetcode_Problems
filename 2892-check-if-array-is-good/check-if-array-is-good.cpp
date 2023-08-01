class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }

        if(n != maxi+1){
            return false;
        }

        else if(n == maxi+1){
            for(auto it: mpp){
                int x = it.first;
                int y = it.second;
                if(x != maxi && mpp[x] != 1){
                    return false;
                }
                else if(x == maxi && mpp[x] != 2){
                    return false;
                }
            }
            return true;
        }
        return true; 
    }
};