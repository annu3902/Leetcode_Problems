class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for(int i=0; i<words.size(); i++){
            vector<int> freq (26, 0);

            for(auto &character : words[i]){
                freq[character - 'a']++;
            }

            for(int i=0; i<26; i++){
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for(int i=0; i<26; i++){
            while(minFreq[i] > 0){
                ans.push_back(string(1, i+'a'));
                minFreq[i]--;
            }
        }
        return ans;
    }
};