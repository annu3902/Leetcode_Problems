class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            char ch = s[i];
            while (i < n && s[i] == ch)
            {
                i++;
                c++;
            }
            i--;
            for (int j = 0; j < min(2, c); j++)
            {
                ans += ch;
            }
        }
        return ans;
    }
};