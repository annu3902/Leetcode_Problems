class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int count=0;
        if(n < 3) return 0;

        for(int i=0; i<n-2; ++i){
            int sum=nums[i];
            for(int j=i+1; j<n-1; ++j){
                sum+=nums[j];
                for(int k=j+1; k<n; ++k){
                    if(sum > nums[k]){
                        count++;
                    }
                }
                sum-=nums[j];
            }
        }
        return count;
    }
};