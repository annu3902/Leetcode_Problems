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

    vector<string> validStrings(int n) {
        vector<string> ans;
        if(n == 1) return {"0", "1"};
        vector<string> nums;
        
        for(int i=1; i<pow(2,n); i++){
            // cout<<i <<" ";
            string s = detobi(i, n);
            nums.push_back(s);
        }
        // cout<<endl;

        // for(string s : nums) cout <<s<<" ";

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
    }
};