class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n =nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n-k];

        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
        }

        while(--k){
            pq.pop();
        }
        return pq.top();

    }
};