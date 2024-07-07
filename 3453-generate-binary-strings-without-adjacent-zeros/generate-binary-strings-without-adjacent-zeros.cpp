class Solution {
public:
    string detobi(int n, int length){
        string ans;
        while(n){
            int rem = n % 2;
            n /= 2;
            ans.push_back(rem + '0');
        }

        while(ans.size() < length) ans.push_back('0');
        reverse(begin(ans), end(ans));
        return ans;
    }

    /*vector<string> validStrings(int n) {
        vector<string> ans;
        if(n == 1) return {"0", "1"};
        vector<string> nums;
        
        for(int i=1; i<pow(2,n); i++){
            string s = detobi(i, n);
            nums.push_back(s);
        }

        for(int i=0; i < nums.size(); i++){
            bool flag = true;
            for(int j=1; j < n; j++){
                if(nums[i][j] == '0' && nums[i][j-1] == '0'){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(nums[i]);
        }

        return ans;
    }*/

    vector<string> validStrings(int n){

        string s;
        for(int i=0; i<n; i++) s+='0';
        vector<string> ans;
        dfs(s, 0, n, ans);

        return ans;
    }

    void dfs(string s, int start, int length, vector<string> &ans){
        if(start >= length){
            for(int i=1; i<length; i++){
                if(s[i] == '0' && s[i-1] == '0') return; 
            }
            ans.push_back(s);
            return;
        }

        dfs(s, start+1, length, ans);

        s[start] = '1';
        dfs(s, start+1, length, ans);
    }





};