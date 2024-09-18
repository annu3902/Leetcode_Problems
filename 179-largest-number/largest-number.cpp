   
class Solution {
public:
    static  bool customCompare(const string &a, const string &b) {
    return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(int x:nums)
        {
            ans.push_back(to_string(x));
        }
        sort(ans.begin(), ans.end(), customCompare);
        if(ans[0]=="0")
        {
            return "0";
        }
        string result;
        for(string x:ans)
        {
            result+=x;
        }
        return result;

    }
};