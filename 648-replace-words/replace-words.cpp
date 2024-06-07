class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(), dictionary.end());  // Initialize set with dictionary words

        stringstream ss(sentence);
        string word;
        string result;

        while (ss >> word) {
            string prefix;
            for (int j = 1; j <= word.size(); ++j) {
                prefix = word.substr(0, j);  // Get prefix of length j
                if (st.find(prefix) != st.end()) {
                    break;  // Found a prefix in the dictionary
                }
            }
            if (!result.empty()) {
                result += " ";
            }
            result += prefix;
        }

        return result;
    }
};
