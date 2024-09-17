class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 = s1 + ' ';
        s2 = s2 + ' ';
        unordered_map<string, int> mp;

        int l1 = s1.length();
        int l2 = s2.length();

        string s = "";
        for(int i = 0; i < l1; i++)
        {
            if(s1[i] == ' ')
            {
                mp[s]++;
                s = "";
            }
            else
            {
                s = s + s1[i];
            }    
        }

        s = "";
        for(int i = 0; i < l2; i++)
        {
            if(s2[i] == ' ')
            {
                mp[s]++;
                s = "";
            }
            else
            {
                s = s + s2[i];
            }    
        }

        vector<string> ans;
        for(auto x: mp)
        {
            if(x.second == 1) ans.push_back(x.first);
        }

        return ans;
    }
};