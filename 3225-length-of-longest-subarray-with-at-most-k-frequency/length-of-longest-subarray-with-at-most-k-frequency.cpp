class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        cout<<n<<" ";
        unordered_map<int, int> mpp;
        int left=0;
        int maxLen = 0;
        int right=0;

        for(; right<n; right++){
            int x = nums[right];
            mpp[x]++;

            if(mpp[x] > k){
                maxLen = max(maxLen, right-left);
                while(left < right && mpp[x] > k){
                    mpp[nums[left++]]--;
                }
            }
        }
        maxLen = max(maxLen, right-left);
        return maxLen;
    }
};