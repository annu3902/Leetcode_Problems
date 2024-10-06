class Solution {
public:
    bool areSentencesSimilar(string str1, string str2) {
        if(str1.size()<str2.size()) swap(str1,str2); // to ensure str1 is always the longer or equal sized string.

        stringstream ss1(str1);
        stringstream ss2(str2);
        vector<string> s1,s2;
        string words;
        while(ss1 >> words) s1.push_back(words);
        while(ss2 >> words) s2.push_back(words);

        //i,j Pointer for s1(larger)
        //a,b Pointer for s2(smaller)
        int i = 0, a=0;
        int j=s1.size()-1; 
        int b=s2.size()-1;

        //match from the beginning
        while(i<s1.size() && a<s2.size() && s1[i]==s2[a]){
            i++;
            a++;
        }
        //match from the beginning
        while(a<=b && s1[j]==s2[b]){
            j--;
            b--;
        }
        if(a<=b) return false;
        return true;
    }
};