// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         vector<char> hashh(26);
//         string ans;

//         for(int i =0; i<26; i++){
//             if(i == 0){
//                 hashh[i] = 'Z';
//             }
//             else{
//                 hashh[i] = i-1 + 'A';
//             }
//             // hashh[i] = 65 + i;
//         }

//         while(columnNumber != 0){
//             int last_digit = columnNumber % 26;
//             ans.push_back(hashh[last_digit]);
//             columnNumber /= 26;
//         }

//         cout<<ans<<" ";
//         reverse(ans.begin(), ans.end());
//         cout<<ans<<" ";
//         return ans;
//     }
// };

class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> hashh(26);
        string ans;

        for (int i = 0; i < 26; i++) {
            if (i == 0) {
                hashh[i] = 'Z';
            } else {
                hashh[i] = i - 1 + 'A';
            }
        }

        while (columnNumber != 0) {
            int last_digit = columnNumber % 26;

            if (last_digit == 0) {
                ans.push_back('Z');  // Special case for remainder 0
                columnNumber = (columnNumber / 26) - 1;
            } else {
                ans.push_back(hashh[last_digit]);
                columnNumber /= 26;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
