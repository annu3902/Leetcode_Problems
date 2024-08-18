class Solution {
public:
    const int mxN = 1e5;
    int nthUglyNumber(int n) {
        vector<int> dparr(n+1);
        dparr[1] = 1;
        int j,k,l;
        j = 1; k = 1; l = 1;
        for(int i = 2; i <= n; i++){
            dparr[i] = min({2*dparr[j], 3*dparr[k], 5*dparr[l]});
            if(dparr[i] == 2*dparr[j]) j++;
            if(dparr[i] == 3*dparr[k]) k++;
            if(dparr[i] == 5*dparr[l]) l++;
        }
        return dparr[n];
    }
};