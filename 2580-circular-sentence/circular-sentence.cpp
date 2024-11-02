class Solution {
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.size(); 
        if(sentence[0] != sentence[size-1]) return false; 
        int isCirculer = true; 
        for(int i =0 ; i < size - 2 ;i++) {
             if(sentence[i] != sentence[i+2] &&  sentence[i+1] == ' ') {
                isCirculer = false; 
                break; 
             }   
        }

       
        return isCirculer; 
    }
};