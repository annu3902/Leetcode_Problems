class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int count = 0;

        for(auto it : mp){
            int key = it.first;
            int freq = it.second;

            if(freq > 1){
                int extra = freq - 1;
                mp[it.first + 1] += extra;
                count += extra;
            }
        }

        return count;
        
        // 1 1 2 2 3 7
        
        // Greedy Approach ->  the array is already sorted, the elements will always be lesser than or equal to the previous element
        /*for(int i=1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                count += (nums[i-1] - nums[i] + 1);
                nums[i] = nums[i-1] + 1;
            } 
        }
        
        return count;*/
    }
};