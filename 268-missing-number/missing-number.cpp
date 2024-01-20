class Solution {
public:
    bool linearSearch(vector<int> &nums, int key){
        for(int x : nums){
            if(x == key) return true;
        }
        return false;
    }

    int missingNumber(vector<int>& nums) {
        for(int i =0; i<=nums.size(); i++){
            if(linearSearch(nums, i) == 0) return i;
        }
        return -1;
    }
};