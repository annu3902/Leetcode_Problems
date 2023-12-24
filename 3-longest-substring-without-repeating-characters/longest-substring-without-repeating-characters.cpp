// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {

//         int n =s.size();
//         int i =0;
//         int j =0;
//         int max_length = 0;
//         set<char> st;

//         for(j =0; j<n; j++){
//             if(st.find(s[j]) == st.end()){
//                 st.insert(s[j]);
//             }

//             else{
//                 max_length = max(max_length, j-i);

//                 while(st.find(s[j]) != st.end()){
//                     st.erase(s[i]);
//                     i++;
//                 }
//                 st.insert(s[j]);
//             }
//         }
//         max_length = max(max_length, j-i);
//         return max_length;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map<char, int> mpp;
        // int maxi = 0;
        // int length = 0;
        // int j = 0;

        // for (int i = 0; i < s.size(); i++) {
        //     if (mpp.find(s[i]) == mpp.end()) {
        //         mpp[s[i]]++;
        //         length++;
        //     } 
        //     else {
        //         maxi = max(maxi, length);
        //         while (mpp[s[i]] != 0) {
        //             mpp.erase(s[j]);
        //             j++;
        //             length--;
        //         }
        //         // cout<<length<<endl;
        //         mpp[s[i]]++;
        //     }
        // }
        // cout << length;
        // maxi = max(maxi, length);
        // return maxi;
        map<char,int> mpp;
        int i=0;
        int j=0;
        int maxi = 0;

        for(; i<s.size(); i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]]++;
            }
            else{
                maxi = max(maxi, i-j);
                while(mpp.count(s[i])){
                    mpp.erase(s[j]);
                    j++;
                }
                mpp[s[i]]++;
            }
        }
        cout<<i<<" "<<j<<endl;
        maxi = max(maxi, i - j);
        return maxi;
    }
};