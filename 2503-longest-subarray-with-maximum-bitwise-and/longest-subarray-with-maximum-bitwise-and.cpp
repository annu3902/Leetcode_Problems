class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin() , nums.end());
        int cnt = 0;
        int maxCnt = 0;
        cout<<maxElement<<" ";

        for(int i = 0; i < n; i++){
            if(nums[i] == maxElement)cnt++;
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;

    }
};