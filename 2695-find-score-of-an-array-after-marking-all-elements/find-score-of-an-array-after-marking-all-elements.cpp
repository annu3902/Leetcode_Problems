class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        long long int sum = 0;

        while(!pq.empty())
        {
            //for mutliple element use vector in map
            // take care of the position that you are using.
            // usually in this case we can also take help of heap 
            // that is min heap which can store element easily and also sort 
            // then first by element and then by index
            int ele = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            
                if(vis[pos] == 0)
                {
                    vis[pos] = 1;
                    sum += ele;
                    pos + 1 < n ? vis[pos + 1] = 1 : 0;
                    pos - 1 >= 0 ? vis[pos - 1] = 1 : 0;
                }
        }
        return sum;
    }
};