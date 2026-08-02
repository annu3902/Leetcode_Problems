class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int left = 0;
        // vector<int> freq(26, 0);
        map<char,int> freq;

        for(int right = 0; right < n; right++){
            freq[s[right]]++;

            while(left <= right && freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            int length = right - left + 1;
            maxLength = max(maxLength, length);
     
        }

        return maxLength;
    }
};