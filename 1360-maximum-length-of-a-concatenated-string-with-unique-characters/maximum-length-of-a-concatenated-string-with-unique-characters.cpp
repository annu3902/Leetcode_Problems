class Solution {
public:

    bool checker(string currString, vector<int> &selected){
        vector<int> temp(26, 0);

        for(int i=0; i<currString.size(); i++){
            char ch = currString[i];
            if(temp[ch - 'a'] == 1) return false;
            temp[ch - 'a'] = 1;
        }

        for(int i =0; i<currString.size(); i++){
            char ch = currString[i];
            if(selected[ch - 'a'] == 1) 
                return false;
        }
        return true;
    }

    int helper(vector<string>& arr, int ind, vector<int> &selected, string &temp, int length){
        // If the string has elements different from that of what we have taken then we have the possibility to select or neglect that string - and the best possible length come out from there is our ans
        if(ind == arr.size()){
            return length;
        }

        string st = arr[ind];
        if(checker(st, selected) == false){
            return helper(arr, ind + 1, selected, temp, length);
        }
        // else{
            // Pick
               for(int i=0; i<st.size(); i++){
                   char ch = st[i];
                   temp += ch;
                   selected[ch - 'a'] = 1;
               }
            int len1 = helper(arr, ind + 1, selected, temp, length + st.size());      

            // Skip
            for(int i =0; i<st.size(); i++){
                char ch = st[i];
                temp.pop_back();
                selected[ch - 'a'] = 0;
            }
            int len2 = helper(arr, ind + 1, selected, temp, length);
        // }
        return max(len1, len2);
    }

    int maxLength(vector<string>& arr) {
        vector<int> selected(26, 0);
        string temp;
        return helper(arr, 0, selected, temp, 0);
    }
};