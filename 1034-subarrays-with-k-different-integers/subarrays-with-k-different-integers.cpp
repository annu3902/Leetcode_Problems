class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt2 = slidingWindow(nums, k);
        int cnt1 = slidingWindow(nums, k-1);
        cout<<cnt1<<" "<<cnt2;

        return (cnt2 - cnt1);
    }

    int slidingWindow(vector<int> &nums, int k){
        int n = nums.size();

        int i=0;
        int j=0;
        int cnt = 0;
        unordered_map<int, int> mp;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size() <= k) cnt += (j-i+1); // Count all the subarrays ending at index j; they will have less than or equal to k different elements.
            
            j++;
        }
        return cnt;
    }
};