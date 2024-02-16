class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int, int> freq; // {element, freq}
        for(int x : nums){
            freq[x]++;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(auto it : freq){
            pq.push({it.second, it.first}); //{freq, element}
        }

        while(k>0 && !pq.empty()){
            vector<int> top = pq.top();
            int freq = top[0];
            int element = top[1];

            if(freq <= k){
                k-=freq;
                pq.pop();

            }

            else{
                k=0;                
            }
        }
        return pq.size();
    }
};