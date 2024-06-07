class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(begin(dictionary), end(dictionary));

        stringstream ss (sentence);
        string word;

        string result="";

        while(ss >> word){

            // if(word == " "){
            //     result.push_back(' ');
            //     continue;
            // }

            string temp="";
            bool flag = false;
            for(int i=0; i<word.size(); i++){
                temp += word[i];
                if(st.find(temp) == st.end()) continue;

                else{
                    flag = true;
                    result += (temp);
                    break;
                }
            }
            if(flag == false) result += (temp);
            result +=" ";
            
        }
        result.pop_back();
        return result;
    }
};