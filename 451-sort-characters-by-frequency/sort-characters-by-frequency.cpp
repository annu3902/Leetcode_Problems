class Solution {
public:
    string frequencySort(string s) {
        string ans;
        map<char,int> mpp;
        for(int i=0; i<s.size(); i++)
        {
            mpp[s[i]]++;
        }
        multimap<int,char,greater<int>> mp;
        for(auto it:mpp){
            mp.insert({it.second,it.first});
        }
        for(auto x: mp){
            int cnt = 0;
            while(cnt < x.first){
                char ch = x.second;
                ans.push_back(ch);
                cnt ++;
            }
        }
        return ans;
    }
};