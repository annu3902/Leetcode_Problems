class Solution {
public:
vector<string> digitExtraction(vector<int>& nums){
    vector<string> ans;

    for(int x : nums){

        string temp;
        if(x == 0) temp.push_back('0');
        while(x){
            int rem = x % 10;
            temp.push_back(rem + '0');

            x = x/10;
        }

        reverse(begin(temp), end(temp));
        ans.push_back(temp);

    }

    return ans;
}

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<string> result = digitExtraction(nums);
        map<int, vector<string>> mp;

        for(string s : result){
            int number = 0;
            for(int i=0; i<s.size(); i++){
                // cout<<mapping[s[i] - '0'];
                number = number*10 + mapping[s[i] - '0'];
            }
            mp[number].push_back(s);
            // cout<<number<<" ";
        }

        vector<int> ans;

        for(auto it : mp){
            int number = it.first;
            // cout<<it.first<<" ";
            for(int i=0; i<it.second.size(); i++){
                stringstream ss;
                ss<<it.second[i];
                int ele = 0;
                ss >> ele;
                // int ele = atoi(it.second[i]);
                ans.push_back(ele);
            }
        }

        return ans;
    }
};