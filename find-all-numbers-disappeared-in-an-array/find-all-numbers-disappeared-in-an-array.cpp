class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
       unordered_map<int,int> mpp;

        // mpp.insert(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for(int i=1; i<=nums.size(); i++)
        {
            if(mpp[i] == 0)
            {
                v.push_back(i);
            }
        }
    return v;
    }
};