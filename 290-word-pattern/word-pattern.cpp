class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> arr;
        string temp;

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                temp.push_back(s[i]);
            }
            else{
                arr.push_back(temp);
                temp.clear();
            }
        }
        // string st = s.substr(a , i-a);
        // arr.push_back(st);
        if(!temp.empty())
            arr.push_back(temp);
        int m = arr.size();
        int n = pattern.length();
        if(n != m) return false;

        map<char, string> mpp1;
        map<string, char> mpp2;
        int left = 0;
        int right = 0;

        while(left < n && right < m){
            char ch = pattern[left];
            string st = arr[right];

            if(mpp1.find(ch) != mpp1.end()){
                if(mpp1[ch] != st) return false;
            }
            else{
                mpp1[ch] = st;
            }

            if(mpp2.find(st) != mpp2.end()){
                if(mpp2[st] != ch) return false;
            }
            else{
                mpp2[st] = ch;
            }
            // else{
            // }
            
            left++;
            right++;
        }
        return true;

    }

};