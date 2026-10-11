class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n = nums.size();
        // vector<int> freq(128,0); 
        unordered_map<char, int> mp;
        int maxi = 0;
        int start = 0; 
        int end = 0;

        while(end < n){
            mp[nums[end]]++;

            maxi = max(maxi, end - start);
            while(start < n && mp[nums[end]] > 1){
                mp[nums[start]]--;
                start++;
            }

            end++;
        }

        maxi = max(maxi, end - start);

        return maxi;
    }
};