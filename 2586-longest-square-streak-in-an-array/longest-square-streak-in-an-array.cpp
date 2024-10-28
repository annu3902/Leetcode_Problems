class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mpp;
        int maxStreak = 0;
        sort(nums.begin() , nums.end());
        for(int &num:nums){
            int Root = (int)sqrt(num);// convert
            if(Root * Root== num && mpp.find(Root) != mpp.end()){
            mpp[num] = mpp[Root] + 1;
            }
            else { 
                mpp[num] = 1;
            }
            maxStreak = max(maxStreak , mpp[num]);
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
};