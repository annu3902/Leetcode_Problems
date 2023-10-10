class Solution {
public:
    string convertToTitle(int columnNumber) {
        map<int, char> mpp; 

        mpp[0] = 'Z';
        for(int i=1; i<26; i++){
            mpp[i] = 64 + i; 
        }

        string ans;
        while(columnNumber > 0){
            int last_digit = columnNumber % 26;

            if(last_digit == 0){
                ans.push_back('Z');
                columnNumber = (columnNumber / 26) - 1;
            }
            else{
                ans.push_back(mpp[last_digit]);
                columnNumber = columnNumber / 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};