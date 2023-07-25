class Solution {
public:
    bool isAnagram(string s, string t) 
    {

        // int mpp_s[26] ={0};
        // int mpp_t[26] ={0};

        // for(int i=0; i<s.size(); i++)
        // {
        //     int ch = s[i] - 'a';
        //     mpp_s[ch] ++;
        // }
        
        // for(int i=0; i<t.size(); i++){
        //     int ch = t[i] - 'a';
        //     mpp_t[ch] ++;
        // }

        // for(int i=0; i<26; i++)
        // {
        //     if(mpp_s[i] != mpp_t[i]){
        //         return false;
        //     }
        // }
        // return true;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        bool result = (s == t)? true: false;
        return result;
    }
};