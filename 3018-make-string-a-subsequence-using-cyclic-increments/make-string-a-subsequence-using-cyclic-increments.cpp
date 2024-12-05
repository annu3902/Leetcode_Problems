class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        string s = str1;
        string p = str2;
        int n = p.size();
        int j =0;
        
        for(int i =0; i<s.size(); i++){
            if(p[j] == s[i]){
                j++;
            }
            else if(p[j] == s[i] +1){
                j++;
            }
            
            else if(s[i] == 'z' && p[j] == 'a'){
                j++;
            }
        }
        
        if(j == n){
            return true;
        }
        return false;
    }
};