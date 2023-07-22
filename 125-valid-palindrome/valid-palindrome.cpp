// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string t = "";
//         for(int i =0; i<s.size(); i++)
//         {
//             if(s[i] >= 65 && s[i] <= 90){
//                 t.push_back(s[i] - 'A' + 'a');
//             }

//             else if(s[i] >= 97 && s[i] <= 122){
//                 t.push_back(s[i]);
//             }

//             else if(s[i] >= 48 && s[i] <= 57){
//                 t.push_back(s[i]);
//             }

//             else{
//                 continue;
//             }
//         }

//         for(int i=0; i<t.size(); i++)
//         {
//             cout<<t[i];
//         }
//         string temp = t;
//         reverse(temp.begin(), temp.end());
        
//         for(int i=0; i<temp.size(); i++)
//         {
//             if(temp[i] != t[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i = 0, j = s.size() - 1;
//         while (i < j) {
//             if (!isalnum(s[i])) {
//                 i++;
//                 continue;
//             }
//             if (!isalnum(s[j])) {
//                 j--;
//                 continue;
//             }
//             if (tolower(s[i]) != tolower(s[j]))
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        string v;
        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i] >= 65 &&  s[i] <= 90){
                s[i] += 32;
                v.push_back(s[i]);
            }
            else if(s[i]>=48 && s[i] <= 57){
                v.push_back(s[i]);
            }
            else if(s[i] >= 97 && s[i] <= 122){
                v.push_back(s[i]);
            }
        }
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i];
        }
        
        // int temp = v;
        int i = 0; 
        int j = v.size()-1;
        while(i < j){
            if(v[i] != v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
   }
};
