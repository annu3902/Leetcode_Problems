class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum =0;
        int n =nums.size();
        mpp[0] = 0;


        for(int i=0; i<n; i++)
        {
            sum += nums[i];

            if(sum % k == 0){
                int length = i + 1;
                if(length >= 2) return true; 
            } 

            if(mpp.find(sum % k) != mpp.end()){
                int len = i + 1 - mpp[sum % k];
                if(len >= 2){
                    return true;
                }
                // }else{
                //     return false;
                // }
            }
            
            if(mpp.find(sum % k) == mpp.end()){
                mpp[sum % k] =i+1;

            }
        }
        return false;
    }
};