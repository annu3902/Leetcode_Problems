class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        for(int i=0; i<numbers.size(); i++)
        {
            int rem = target - numbers[i];
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem]+1, i+1};
            }

            mpp[numbers[i]] =i;
        }
        return {-1,-1};
    }
};