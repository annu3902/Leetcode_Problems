class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp1;
        map<char, char> mpp2;
        int left = 0;
        int right = 0;
        int n = s.size();

        while(left < n && right < n){
            if(mpp1.find(s[left]) != mpp1.end()){
                if(mpp1[s[left]] != t[right] && mpp2[t[right]] != s[left]) return false;
                // else return false;
            }
            if(mpp2.find(t[right]) != mpp2.end()){
                if(mpp2[t[right]] != s[left] && mpp1[s[left]] != t[right]) return false;
                // else return false;
            }

            mpp1[s[left]] = t[right];
            mpp2[t[right]] = s[left];
            left++;
            right++;
        }
        return true;
    }
};