class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(rank[parent_x] == rank[parent_y]){
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }

        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }

        else{
            parent[parent_x] = parent_y;
        }
    }

    bool equationsPossible(vector<string>& nums) {
        int n = nums.size();
        parent.resize(26);
        rank.resize(26,0);
        iota(begin(parent), end(parent), 0);

        for(int i=0; i<nums.size(); i++){
            int x = nums[i][0] - 'a';
            int y = nums[i][3] - 'a';

            if(nums[i][1] == '=') unionSet(x, y);
        }

        for(int i=0; i<nums.size(); i++){
            int x = find(nums[i][0] - 'a');
            int y = find(nums[i][3] - 'a');

            if(nums[i][1] == '!' && x == y) return false; 
        }
        return true;
    }
};