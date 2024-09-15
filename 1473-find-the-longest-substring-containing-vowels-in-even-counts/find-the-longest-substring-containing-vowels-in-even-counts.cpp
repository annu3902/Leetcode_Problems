class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

        return false;
    }

    int findTheLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        unordered_map<char, char> charMap;
        charMap['a'] = '0';
        charMap['e'] = '1';
        charMap['i'] = '2';
        charMap['o'] = '3';
        charMap['u'] = '4';
 
        string st = "11111";
        unordered_map<string, int> mp;

        mp[st] = 0;

        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                char index = charMap[s[i]];
                st[index - '0'] = '1' - st[index - '0'] + '0';
                // cout<<st<<" ";
                if(mp.count(st)){
                    int length = i+1 - mp[st];
                    maxi = max(maxi, length);
                }

                else{
                    mp[st] = i+1;
                }
            }

            else{
                if(mp.count(st)){
                    int length = i+1 - mp[st];
                    maxi = max(maxi, length);
                }
            }
        }

        return maxi;
    }
};