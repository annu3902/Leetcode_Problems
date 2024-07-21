class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int ans = 0;
        bool flag = false;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                flag = false;
                count++;
            }
            else{
                if(!flag) ans += count;
                flag = true;
            }
        }

        return ans;
    }
};