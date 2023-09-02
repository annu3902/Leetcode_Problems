class Solution {
public:
    void reverseStringHelper(int left, int right,vector<char> &s){
        // Writting Base Condition 
        if(left >= right) return;

        // Call recursion to do later 
        reverseStringHelper(left+1, right-1, s);
        
        // Do small task - 2
        swap(s[left], s[right]);


    }

    void reverseString(vector<char>& s) {
        reverseStringHelper(0, s.size()-1, s);
    }
};