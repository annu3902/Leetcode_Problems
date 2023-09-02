class Solution {
public:
    string reverseVowels(string s) {
    unordered_set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        int start =0;
        int end = s.size()-1;

        while(start <= end){
            if(st.count(s[start]) && st.count(s[end])){
                swap(s[start], s[end]);
                start++;
                end--;
            }

            else if(st.find(s[start]) == st.end()){
                start++;
            }

            else if(st.find(s[end]) == st.end()){
                end--;
            }
        }
        return s;
    }
};