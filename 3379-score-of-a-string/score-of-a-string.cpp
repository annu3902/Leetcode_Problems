class Solution {
public:
    int scoreOfString(string s) {
        long sum = 0;
        for(int i=1; i<s.size(); i++){

            sum += (int)abs(s[i] - s[i-1]);

        }
        return sum;
    }
};