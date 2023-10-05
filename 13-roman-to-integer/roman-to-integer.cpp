class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        map<char, int> mpp{
            {'I', 1}, {'V',5}, {'X',10}, {'L',50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int sum = mpp[s[n-1]];

        for(int i =n-2; i>=0; i--){
            if(mpp[s[i]] < mpp[s[i+1]]){
                sum -= mpp[s[i]];
            }
            else{
                sum += mpp[s[i]];
            }
        }
        return sum;
    }
};