class Solution {
public:
    string clearStars(string s) {
        int n=s.size();

        vector<vector<int>> vec(26);
        unordered_set<int> st;

        for(int i = 0; i<n; i++){

            if(s[i] != '*')vec[s[i] - 'a'].push_back(i);

            else{
                for(int k=0; k<26; k++){
                    // 0 -> 'a'
                    // 1 -> 'b'
                    if(vec[k].empty()){
                        continue;
                    }
                    else{
                        st.insert(vec[k].back());   
                        vec[k].pop_back();
                        break;
                    }
                }
            }
        }

        string ans="";

        for(int i=0; i<n; i++){
            if(s[i] == '*') continue;

            else if(st.count(i)) continue;

            else{
                ans += s[i];
            }

        }
        return ans;
        
    }
};