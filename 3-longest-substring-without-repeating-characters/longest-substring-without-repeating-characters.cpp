class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int start = 0;
        int end = 0;
        unordered_map<char, int> mp;
        int maxLength = 0;

        while(end < n){
            mp[s[end]]++;
            while(start < n && mp[s[end]] >= 2){
                int length = end - start;
                maxLength = max(maxLength, length);
                mp[s[start]]--;
                if(mp[s[start]] == 0){
                    mp.erase(start);
                }
                start++;
            }
            end++;
        }

        maxLength = max(maxLength, end - start);
        return maxLength;
    }
};