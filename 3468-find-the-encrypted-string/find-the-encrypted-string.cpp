class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans;

        for(int i=0; i< s.size(); i++){
            ans.push_back(s[(i+k) % n]);
        }

        return ans;
    }
};