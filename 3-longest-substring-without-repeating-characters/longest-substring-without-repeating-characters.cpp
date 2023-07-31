// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         list<char> ls;
//         int n =s.size();
//         if(n == 0) return 0;
//         if(n == 1) return 1;
//         int i=0;
//         int j=0;
//         int maxi = 0;
//         map<char,int> mpp;
//         while(j < n && mpp[s[j]] <= 1){
//             // ls.push_back(s[j]);
//             mpp[s[j]]++;
//             while(mpp.find(s[j]) != mpp.end()){
//                 int len = j-i+1;
//                 maxi = max(maxi, len);
//                 ls.pop_front();
//                 i++;
//             }

//             ls.push_back(s[j]);
//             j++;
//         }
//         maxi = max(maxi, j-i+1);
//     return maxi;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int i = 0;
        int j = 0;
        int maxi = 0;
        unordered_map<char, int> mpp;
        
        while (j < n) {
            mpp[s[j]]++;
            while (mpp[s[j]] > 1) {
                int len = j - i + 1;
                maxi = max(maxi, len);
                mpp[s[i]]--;
                i++;
            }

            j++;
        }
        maxi = max(maxi, j - i + 1);
        return maxi-1;
    }
};
