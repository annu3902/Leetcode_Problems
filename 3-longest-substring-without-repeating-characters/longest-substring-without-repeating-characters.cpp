class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n =s.size();
        int i =0;
        int j =0;
        int max_length = 0;
        set<char> st;

        for(j =0; j<n; j++){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
            }
            
            else{
                max_length = max(max_length, j-i);

                while(st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
            }
        }
        max_length = max(max_length, j-i);
        return max_length;
    }
};