class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> indices; // stores the index of the maximum element which is last seen
        long long result = 0;

        for(int i=0; i<n; i++){

            if(nums[i] == maxElement){
                indices.push_back(i);
            }

            int size = indices.size();
            if(size >= k){
                int last_index = indices[size - k];
                result += (last_index + 1);
            }

        }

        return result;
    }
};