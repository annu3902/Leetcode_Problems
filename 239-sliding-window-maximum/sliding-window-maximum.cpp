class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int left = 0;
        int right = 0;
        int n = nums.size();
        priority_queue<pair<int,int>> pq; 

        while(right < n){
            pq.push({nums[right], right});
            if(right - left + 1 < k){
                right++;
                continue;
            }
            
            while(pq.top().second < right - k + 1){
                pq.pop();
                left++;
            }
            ans.push_back(pq.top().first);
            right++;
        }

        return ans;
    }
};