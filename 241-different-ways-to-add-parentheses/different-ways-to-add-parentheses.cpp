class Solution {
public:
    int helper(int x,int y,char c){
        if(c=='+')return x+y;
        else if(c=='-')return x-y;
        else return x*y;
    }
    vector<int> rec(int i,int j,string &s,map<pair<int,int>,vector<int>>&mp){
        if(i==j)return vector<int>{s[i]-'0'};
        int n=s.size();
        vector<int> ans;
        if(mp.count({i,j}))return mp[{i,j}];
        for(int t=i+1;t<j;t++){
            if(s[t]=='+'||s[t]=='-'||s[t]=='*'){
                auto v1=rec(i,t-1,s,mp);
                auto v2=rec(t+1,j,s,mp);
                for(auto x: v1)
                    for(auto y:v2)
                        ans.push_back(helper(x,y,s[t]));
            }
        }

        if(ans.size()==0){
            string t=s.substr(i,j-i+1);
            ans.push_back(stoi(t));
        }
        return mp[{i,j}]=ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        map<pair<int,int>,vector<int>> mp;
        return rec(0,expression.size()-1,expression,mp);
    }
};