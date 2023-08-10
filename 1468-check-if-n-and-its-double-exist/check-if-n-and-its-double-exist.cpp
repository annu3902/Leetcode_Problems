class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      unordered_set<int> st(arr.begin(),arr.end());
        for(auto it : st){
            if( it != 0 && st.find(2*it) != st.end()){
                return true;
            }
        }
        return count(arr.begin(),arr.end(),0) > 1;
    }
    
};