class Solution {
public:
    int minimumDeletions(string s) {
        int count=0;
        int B=0;
        for(int i=0;i<s.length();i++){
             if(s[i]=='b') B++;
             if(B&&s[i]=='a') count++,B--;
        }
        return count;
    }
};