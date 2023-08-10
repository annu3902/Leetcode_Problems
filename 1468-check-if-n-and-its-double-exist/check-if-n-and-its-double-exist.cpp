class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      unordered_set<int> s;
        for(auto a:arr)
        {
            s.insert(a);
        }
        for(auto s1:s)
        {
            if(s1 !=0 && s.find(s1*2)!=s.end()) return true;
        }
        return count(arr.begin(),arr.end(),0) > 1;
        // return false;
    }
    
};