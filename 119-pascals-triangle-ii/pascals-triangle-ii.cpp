class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        vector<int> curr;

        prev.push_back(1);
        curr.push_back(1);

        for(int i=1; i<=rowIndex; i++){

            vector<int> temp(i+1, 1);
            curr = temp;

            for(int j=1; j<i; j++){
                curr[j] = prev[j-1] + prev[j];
            }

            prev = curr;
        }

        return curr;
    }
};