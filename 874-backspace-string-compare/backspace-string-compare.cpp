///// ******* My Solution ******/////////
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> st1;
//         stack<char> st2;

//         for(int i=0; i<s.size(); i++){
//             if(!st1.empty() && s[i] == '#')
//             {
//                 st1.pop();
//                 continue;
//             }
//             else if(st1.empty() && s[i] == '#'){
//                 continue;
//             }

//             st1.push(s[i]);
//         }

//         for(int i=0; i<t.size(); i++){
//             if(!st2.empty() && t[i] == '#')
//             {
//                 st2.pop();
//                 continue;
//             }
//             else if(st2.empty() && t[i] == '#'){
//                 continue;
//             }

//             st2.push(t[i]);
//         }

//         if(st1.size() != st2.size()) return false;
//         if(st1.size()==0 && st2.size()==0) return true;

//         auto it1 = st1.top();
//         auto it2 = st2.top();
//         while(!st1.empty() && !st2.empty()){
//             if((it1) != (it2)){
//                 return false;
//             }
//             st1.pop();
//             st2.pop();
//         }

//         return true;
//     }
// };


class Solution{
    public:
    bool backspaceCompare(string s, string t){
        string st1 ="";
        string st2 ="";

        for(int i =0; i<s.size(); i++){
            if(!st1.empty() && s[i] == '#'){
                st1.pop_back();
                continue;
            }
            else if(st1.empty() && s[i] =='#'){
                continue;
            }

            st1.push_back(s[i]);
        }

        for(int i =0; i<t.size(); i++){
            if(!st2.empty() && t[i] == '#'){
                st2.pop_back();
                continue;
            }
            else if(st2.empty() && t[i] =='#'){
                continue;
            }

            st2.push_back(t[i]);
        }
        
        if(st1.size() != st2.size()) return false;

        int j = 0;
        for(int i =0; i<st1.size() && j < st2.length(); i++){
            if(st1[i] != st2[j]) return false;
            j++;
        }
        return true;
    }
};