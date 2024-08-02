class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();

        int cnt = 0;
        sort(begin(s), end(s));
        sort(begin(g), end(g));

        int i = 0;
        int j = 0;
        while(i < n && j < m){

            if(s[i] >= g[j]){
                cnt++;
                i++;
                j++;
            }

            else if(s[i] < g[j]){
                i++;
            }

        }

        return cnt;
    }
};