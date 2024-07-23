class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string &word : words){
            mp[word]++;
        }

        multimap<int, string, greater<int>> mp2;

        for(auto it : mp){
            mp2.insert({it.second, it.first});
        }

        vector<string> ans;

        for(auto it = mp2.begin(); it != mp2.end() && k > 0; it++){
            ans.push_back((it->second));
            k--;
        }

        return ans;
    }
};