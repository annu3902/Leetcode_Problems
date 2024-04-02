class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int i = 0;
        // int j = 0;
        unordered_map<char, char> mpp;
        unordered_map<char,char> mp;
        while(i<n){
            if(mpp.count(s[i]) || mp.count(t[i])){
            if((mpp[s[i]] != t[i]) || mp[t[i]] != s[i]) return false;
            }
            else
                mpp[s[i]] = t[i];
                mp[t[i]] = s[i];
            i++;
        }
        return true;
    }
};