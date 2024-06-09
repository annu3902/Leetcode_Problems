class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0;
        int minChair = INT_MIN;

        for(char ch : s){
            if(ch == 'E'){
                chair++;
                minChair = max(minChair, chair);
            }
            else {
                chair--;
            }
        }
        return minChair;
    }
};