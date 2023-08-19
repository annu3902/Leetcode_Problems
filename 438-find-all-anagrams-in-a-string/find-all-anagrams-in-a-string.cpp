class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        int start = 0;
        int end = 0;
        unordered_map<char,int> mpp;
        vector<int> ans;
        list<int> ls;
        // sort(p.begin(), p.end());

        for(int i =0; i<k; i++){
            mpp[p[i]]++;
        }

        int distinct_cnt = mpp.size();

        while(end < n){
            // ls.push_back(s[end]);

            if(mpp.find(s[end]) != mpp.end()){
                mpp[s[end]]--;
                if(mpp[s[end]] == 0){
                    distinct_cnt--;
                }
            }

            else{
                // Remove Calculations for start
                // Backtracking Optimization
                // int cnt = 0;
                // while(cnt < k-1){
                //     if(mpp.find(s[start]) != mpp.end()){
                //         mpp[s[start]]++;
                //         if(mpp[s[start]] == 1){
                //             distinct_cnt++;
                //         }
                //         start++;
                //         end++;
                //         cnt++;
                //     }
                // }

                while(start < end){
                    // Remove calculations for start
                    if(mpp.find(s[start]) != mpp.end()){
                        mpp[s[start]]++;
                        if(mpp[s[start]] == 1){
                            distinct_cnt++;
                        }
                    }

                    // Slide the Window
                    start++;
                }
                start++;
                // continue;
            }

            if(end - start +1 < k){
                end++;
            }

            else if(end - start + 1 == k){
                
                cout<<distinct_cnt<<" ";
                if(distinct_cnt == 0){
                    ans.push_back(start);
                    // cout<<start<<" ";
                }

                // Backtracking
                if(mpp.find(s[start]) != mpp.end()){
                    mpp[s[start]]++;
                    // ls.pop_front();

                    if(mpp[s[start]] == 1){
                        distinct_cnt++;
                    }
                }

                // Slide the Window
                start++;
                end++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int n = s.size();
//         int k = p.size();
//         int start = 0;
//         int end = 0;
//         vector<int> charCount(26, 0); // Array to count occurrences of characters
//         vector<int> ans;

//         // Count the occurrences of characters in p
//         for (char c : p) {
//             charCount[c - 'a']++;
//         }

//         int distinct_cnt = k;

//         while (end < n) {
//             // Decrement the count of character in s
//             if(s[end] > 0)
//                 charCount[s[end] - 'a']--;

//             // If the character count becomes negative, it means the character is extra in the window
//             if (charCount[s[end] - 'a'] >= 0) {
//                 distinct_cnt--;
//             }

//             // Slide the window
//             if (end - start + 1 < k) {
//                 end++;
//             } else if (end - start + 1 == k) {
//                 if (distinct_cnt == 0) {
//                     ans.push_back(start);
//                 }

//                 // Increment the count of character that's leaving the window
//                 if (charCount[s[start] - 'a'] >= 0) {
//                     distinct_cnt++;
//                 }

//                 // Slide the window
//                 start++;
//                 end++;
//             }
//         }
//         return ans;
//     }
// };
