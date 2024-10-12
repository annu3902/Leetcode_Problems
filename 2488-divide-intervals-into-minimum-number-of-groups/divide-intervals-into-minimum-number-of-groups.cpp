
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> st;
        vector<int> end;

        for(vector<int> interval: intervals){
            st.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(st.begin(), st.end());
        sort(end.begin(), end.end());

        //1 1 2 5  6
        //3 5 8 10 10

        int groups= 0;
        int curr= 0;
        for(int i=0; i<st.size(); i++){
            if(st[i]<=end[curr]){
                groups++;
            }
            else{
                curr++;
            }
        }
        return groups;

    }
};