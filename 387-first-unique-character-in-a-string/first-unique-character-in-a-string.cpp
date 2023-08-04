// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int> hashh(26);
//         for(int i =0; i<s.size(); i++)
//         {
//             hashh[s[i] - 'a']++;
//         }
//         for(int i =0; i<s.size(); i++)
//         {
//             if(hashh[s[i] - 'a'] == 1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution{
    public:
    int firstUniqChar(string s){
        unordered_map<int,int>mpp;
        int n =s.size();
        for(int i=0; i<n; i++)
        {
            mpp[s[i]]++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(mpp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};