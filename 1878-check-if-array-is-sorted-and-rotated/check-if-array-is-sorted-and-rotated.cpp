class Solution {
public:
    bool check(vector<int>& nums) {
        // int maxi = *max_element(begin(nums), end(nums));
        // int mini = *min_element(begin(nums), end(nums));
        
        int x = -1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] >= nums[i-1]){
                continue;
            }
            
            else{
                x = i;
            }
        }
        if(x == -1) return true;
        
        vector<int> temp = nums;
        sort(begin(temp), end(temp));
        
        for(int i=0; i<nums.size(); i++){
            if(temp[i] != nums[(i+x) % nums.size()]){
                return false;
            }
        }     
        
        return true;

    }
};