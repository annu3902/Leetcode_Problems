class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        unordered_map<int,int> map;

        for(int i=0; i<=nums.size()-1;i++)
        {
            int difference = target-nums[i];
            if(map.find(difference)!=map.end())
            {
                // ans.push_back(i); 
                // ans.push_back(map[difference]);
                return {map[difference] , i};
            }
            map[nums[i]] =i;
        }
        // return ans;
        return {-1,-1};
    }
};