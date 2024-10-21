class Solution {
public:
    unordered_set<string>st;
    int helper(string &s,int idx,unordered_set<string>&temp){
        if(idx==s.size()){
           return 0;
        }
        int mx=0;
        string word;
        for(int i=idx;i<s.size();i++){
            word+=s[i];
            if(temp.find(word)==temp.end()){
                temp.insert(word);
                
                int a=1+helper(s,i+1,temp);
                mx=max(a,mx);
                temp.erase(word);
            }
            // word.clear();
        }
        return mx;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>temp;
        return helper(s,0,temp);
        
    }
};