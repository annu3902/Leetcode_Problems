class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi >= k) return 1;

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int bitOr = 0;
            for(int j=i; j<n; j++){
                bitOr |= nums[j];
                if(bitOr >= k){
                    mini = min(mini, j-i+1);
                }
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};