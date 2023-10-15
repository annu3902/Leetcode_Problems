// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
// //         int i =0;
// //         int mini = INT_MAX;
// //         string ans;
// //         list<char> ls;
// //         int j;
        
// //         for(int j=0; j<s.size(); j++){
// //             ls.push_back(s[j]);
// //             if(s[j] == '1'){
// //                 count++;
// //             }
            
// //             if(count == k){
// //                 int len = j - i + 1;
// //                 if(mini > len){
// //                     mini = len;
// //                     // Save the current in ans
// //                     if(ans.size() != 0){
// //                         ans.clear();
// //                     }
// //                     for(auto it : ls){
// //                         ans.push_back(it);
// //                     }
// //                 }
// //                 else if(mini == len){
// //                     // Check for lexicographically smaller
// //                     // list<char>::iterator it = ls.begin();
// //                     int a = 0;
// //                     if(ans.size() != 0){
// //                         for(auto it = ls.begin() ;it != ls.end(); it++){
// //                             if(*(it) < ans[a]){
// //                                 ans.clear(); // clearing the ans
// //                                 for(auto it : ls){
// //                                     ans.push_back(it);
// //                                 }
// //                             }
// //                         }
// //                     }
                    
// //                 }
// //                 else{
// //                     // Not give a shit to the mini < len
// //                 }
// //             }
            
// //             while(count > k){
// //                 // ls.pop_front();
// //                 if(s[i] == '1'){
// //                     count--;
// //                 }
// //                 ls.pop_front();
// //                 i++;
// //             }
// //         }
        
// //         while(j > i){
// //             if (count == k){
                
// //             }
// //             if(s[i] == '1'){
// //                 count--;
// //             }
// //             ls.pop_front();
// //             i++;
// //         }
//             string ans;
//             int n = s.size();
//             int mini = INT_MAX;
        
//            for(int i=0; i<n; i++){
//                string temp = "";
//                int count_ones = 0;
//                temp+=s[i];
//                if(s[i]=='1')count_ones++;
//                if(k==1 && count_ones==1) return temp;
//                for(int j =i+1; j<n; j++){
//                     temp += s[j];
//                    if(s[j] == '1') count_ones++;
//                    if(count_ones == k){
//                        if((temp.size() < mini) || (temp.size() == mini && temp < ans)){
//                            mini = temp.size();
//                            ans = temp;
//                            break;
//                        }
//                    }
//                }
//            }
//         return ans;   
//     }
// };

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        int bestLen = INT_MAX;
        string best;
        
        for (int i = 0; i < n; ++i) {
            string t;
                int ones = 0;
            for (int j = i; j < n; ++j) {
                t += s[j];
                if(s[j]=='1') ones ++;
                if (ones == k) {
                    int len = j - i + 1;
                    if (len < bestLen || (len == bestLen && t < best)) {
                        bestLen = len;
                        best = t;
                        break;
                    }
                }
            }
        }
        return best;
    }
};