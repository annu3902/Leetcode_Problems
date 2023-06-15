// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n =nums.size();

//         if(n == 0) return 0;
//         else if(n == 1) return 1;

//         else{
//             set<int> st;
//             st.insert(nums.begin(), nums.end());
//             int cnt =1;
//             int maxi = 0;
//             for(set<int> :: iterator it =st.begin(); it != st.end(); it++)
//             {
//                 if (st.find(*(it)+1) != st.end())
                    // if(st.find(*(it)+1) != st.end())
//                 {
//                     cnt++;
//                 }

//                 else{
//                     maxi = max(maxi, cnt);
//                     cnt =1;
//                 }
//             }

//             maxi = max(maxi , cnt);
//         return maxi;
//         }
//     return -1;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        else if (n == 1) return 1;

        else {
            set<int> st(nums.begin(), nums.end());
            int cnt = 1;
            int maxi = 0;
            
            for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
                if (st.find(*(it)+1) != st.end()) {
                    cnt++;
                }
                else {
                    maxi = max(maxi, cnt);
                    cnt = 1;
                }
            }

            maxi = max(maxi, cnt);
        return maxi;
        }
        
    return -1;
    }
};