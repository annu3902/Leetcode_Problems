class Solution {
public:

   void recursion(int x,int n,int k,vector<vector<int>> &ans, vector<int> &v){
       if(x>n || k==0){
           if(k==0){
               ans.push_back(v);
           }
           return;
       }

       v.push_back(x);
       recursion(x+1,n,k-1,ans,v);
       v.pop_back();
       recursion(x+1,n,k,ans,v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        recursion(1,n,k,ans,v);
        return ans;

    }
};