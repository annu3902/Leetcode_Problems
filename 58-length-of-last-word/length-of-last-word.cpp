class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int cnt_s = 0;
        int cnt_w = 0;
        for(int i=0; i<n; i++){
            if(s[i]==' ' && cnt_w==0) cnt_s++;
            else if(s[i]!=' ') cnt_w++;
            else return cnt_w;
        }
        return cnt_w;
    }
};