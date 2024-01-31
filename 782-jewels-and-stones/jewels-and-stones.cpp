class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mppJ;

        for(char c: jewels){
            mppJ[c]++;
        }

        int cnt = 0;
        for(char c : stones){
            if(mppJ.count(c)) cnt++;
        }
        return cnt;
    }
};