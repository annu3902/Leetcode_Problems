class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ansCnt = 0;

        for(int j =0; j<s.size(); j++){
            int vovelCnt = 0;
            int consCnt = 0;
            for(int i=j; i<s.size(); i++){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vovelCnt++;
            else{
                consCnt++;
            }

            if(vovelCnt == consCnt){
                int x = vovelCnt;
                if((x*x) % k == 0) ansCnt++;
            }
            }
        }
        return ansCnt++;
    }
};