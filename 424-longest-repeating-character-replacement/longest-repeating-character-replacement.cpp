class Solution {
public:
    int characterReplacement(string s, int k) {
        // Data Declarations
        int i = 0;
        int j = 0;
        int maxLength = 0;
        unordered_map<int, int> mp;
        int maxFrequency = 0;

        // Algorithm
        while(i < s.size()){
            mp[s[i]]++;
            maxFrequency = max(maxFrequency, mp[s[i]]);
            int currLength = i - j + 1;
            if(currLength - maxFrequency <= k){
                maxLength = max(maxLength, currLength);
            }else{
                while(j < s.size() && currLength - maxFrequency > k){
                    mp[s[j]]--;
                    currLength--;
                    // maxFrequency = max(maxFrequency , mp[s[j]])
                    if(mp[s[j]] == 0){
                        mp.erase(s[j]);
                    }
                    j++;
                }
            }
            i++;
        }

        return maxLength;
    }
};