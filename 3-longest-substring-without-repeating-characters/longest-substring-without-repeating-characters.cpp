class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int i = 0;
        int j = 0;
        int max_length = 0;

        while(j < n){
            if(mpp.find(s[j]) == mpp.end()){
                mpp[s[j]]++;
            }

            else{
                max_length = max(max_length, j - i);

                while(mpp.find(s[j]) != mpp.end()){
                    mpp.erase(s[i]);
                    i++;
                }
                mpp[s[j]]++;
            }
            j++;
        }
        max_length = max(max_length, j - i);
        return max_length;
    }
};