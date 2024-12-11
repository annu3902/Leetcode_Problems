class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        int maxlen=0;
        while(l<nums.size()){
            while(r<nums.size() && nums[r]-nums[l]<=2*k){
                r++;
            }
            maxlen=max(maxlen,r-l);
            l++;
        }
        return maxlen;
        
    }
};