class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end());
        unordered_map<char, int> mp1;

        for(auto &character : words[0]){
            mp1[character]++;
        }        

        for(int i=1; i<n; i++){
            unordered_map<char, int> mp2;
            for(auto &character : words[i]){
                mp2[character]++;
            }
            
            unordered_map<char, int> temp;
            for(auto it = mp1.begin(); it!=mp1.end(); it++){
                if(mp2.find(it->first) != mp2.end()){
                    temp[it->first] = min(it->second, mp2[it->first]);
                }
            }
            mp1 = temp;  
        }

    vector<string> ans;
        for(auto it : mp1){
            while(it.second > 0){
                string temp="";
                temp += it.first;
                ans.push_back(temp);
                it.second--;
            }
        }
        return ans;
    }
};