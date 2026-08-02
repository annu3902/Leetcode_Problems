class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        int left = 0;

        for(int right=0; right<=n-1; right++){
            // dq.push_back(right);

            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            while(right - left + 1 > k){
                if(dq.front() <= left){
                    dq.pop_front();
                }
                left++;
            }

            if(right - left + 1 == k)ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};