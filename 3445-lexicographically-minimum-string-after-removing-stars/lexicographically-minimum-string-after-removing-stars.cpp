class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        string ans="";

        map<char, vector<int>> mp;
        for(int i=0; i<n; i++){

            if(isalpha(s[i])){
                mp[s[i]].push_back(i);
            }

            else{
                if(!mp.empty()){
                    char c = mp.begin()->first;

                    mp.begin()->second.pop_back();
                    if(mp.begin()->second.empty()){
                        mp.erase(c);
                    }
                }
            }

        }

        int i = n-1;
        while(i >= 0){

            if(mp.find(s[i]) != mp.end()){
                
                if(mp[s[i]].back() == i){
                    ans.push_back(s[i]);

                    mp[s[i]].pop_back();

                    if(mp[s[i]].empty()){
                        mp.erase(s[i]);
                    } 
                }
            }

            i--;
        }

        reverse(begin(ans), end(ans));

        return ans;

    }
};