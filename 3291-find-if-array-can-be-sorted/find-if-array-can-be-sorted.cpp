class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        if(temp == nums) return true;
        
        for(int i=n-1; i >= 1; i--){
            for(int j =0; j<i; j++){
                if(nums[j] > nums[j+1]){
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        if(temp == nums) return true;
        return false;
    }
};