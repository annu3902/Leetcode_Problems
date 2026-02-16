class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = false;
        } 

        int length = 0;
        int maxLength = 0;

        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] == false){
                mp[nums[i]] = true;
                length = 1;
            
            
            // Explore the right
            int nextElement = nums[i] + 1;
            while(mp.count(nextElement)){
                mp[nextElement] = true;
                nextElement += 1;
                length++;
            }

            // Explore the left
            int prevElement = nums[i] - 1;
            while(mp.count(prevElement)){
                mp[prevElement] = true;
                prevElement -= 1;
                length++;
            }

            maxLength = max(maxLength, length);
            
            }
        }


        return maxLength;
    }
};