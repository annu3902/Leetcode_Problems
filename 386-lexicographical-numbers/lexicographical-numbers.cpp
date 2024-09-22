class Solution {
public:
    void dfs(int currNumber, vector<int>& result, int n){

        if(currNumber > n) return;

        result.push_back(currNumber);

        for(int num=0; num<=9; num++){
            currNumber = currNumber*10 + num;
            if(currNumber > n) return;
            dfs(currNumber, result, n);
            currNumber = currNumber/10;
        }

    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int i=1; i<=9; i++){
            dfs(i, result, n);
        }

        return result;
    }
};