class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        set<char> st = {tasks.begin(), tasks.end()};
        int no_of_tasks=st.size();
        int uniqueTasks = no_of_tasks-1;
        // if(uniqueTasks>=n) return tasks.size();
        int m = tasks.size();

        int maxCount=0;
        unordered_map<char,int>mpp;
        for(char ch : tasks){
            mpp[ch]++;
            maxCount=max(maxCount, mpp[ch]);
        }

        int times=0;
        for(pair<char,int> it : mpp){
            if(it.second==maxCount) times++;
        }
        int ans = maxCount + n*(maxCount-1);
        int add = (times>1)? (times-1): 0; 
        ans += add;
        int result = max(ans,m);
        return result;
    }
};