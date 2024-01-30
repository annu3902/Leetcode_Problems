class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin() , nums.end());
        int cnt = 0;
        int maxCnt = 0;
        cout<<maxElement<<" ";

        for(int i = 0; i < n; i++){
            // if(i - 1 == 0 && nums[0] == maxElement) cnt++;
            while(i < n && nums[i] == maxElement){
                cnt++;
                i++;
            }

            // if(maxCnt < cnt){
            //     maxCnt = cnt;
            //     cnt = 0;
            // }
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
        return maxCnt;

    }
};