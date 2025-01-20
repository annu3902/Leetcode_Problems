class Solution {
public:
    int col[200][200]={0}, globalres=0, rr[4]={0,0,1,-1}, cc[4]={1,-1,0,0};

    void clearset(set<pair<int,int>>& set) {
        for (const auto &p : set) {
            col[p.first][p.second]=0;
        }
        set.clear();
    }

    bool canFill(int x, int y, int h, vector<vector<int>>& hts) {
        queue<pair<int,int>>q;
        set<pair<int,int>>set;
        col[x][y]=2;
        set.insert(make_pair(x,y));
        q.push(make_pair(x,y));
        while(!q.empty()) {
            int ux = q.front().first;
            int uy = q.front().second;
            q.pop();
            if(ux==0||uy==0||ux+1==hts.size()||uy+1==hts[ux].size()) {
                clearset(set);
                return false;
            }
            for(int i=0;i<4;i++) {
                int vx = ux+rr[i];
                int vy = uy+cc[i];
                if (vx<0||vy<0||vx>=hts.size()||vy>=hts[vx].size()) continue;
                if(col[vx][vy]==1) {
                    clearset(set);
                    return false;
                }
                if(col[vx][vy]==2) continue;
                if(h<=hts[vx][vy]) continue;
                col[vx][vy]=2;
                set.insert(make_pair(vx,vy));
                q.push(make_pair(vx,vy));
            }
        }
        clearset(set);
        return true;
    }

    void fill(int x, int y, int h, vector<vector<int>>& hts) {
        queue<pair<int,int>>q;
        set<pair<int,int>>set;
        col[x][y]=1;
        //set.insert(make_pair(x,y));
        q.push(make_pair(x,y));
        while(!q.empty()) {
            int ux = q.front().first;
            int uy = q.front().second;
            q.pop();
            globalres+=max(0,h-hts[ux][uy]);
            for(int i=0;i<4;i++) {
                int vx = ux+rr[i];
                int vy = uy+cc[i];
                if (vx<0||vy<0||vx>=hts.size()||vy>=hts[vx].size()) continue;
                if(col[vx][vy]==1) continue;
                if(h<=hts[vx][vy]) continue;
                col[vx][vy]=1;
                q.push(make_pair(vx,vy));
            }
        }
    }

    void floodFillBinarySearch(int x, int y, int minh, vector<vector<int>>& hts) {
        int res=0, low=minh+1, high=20000;
        while(low<=high) {
            int mid = (low+high)/2;
            if (canFill(x,y,mid,hts)) {
                res=max(res,mid);
                low=mid+1;
            } else {
                high=mid-1;
            }
        }

        if (minh<res) {
            fill(x,y,res,hts);
        }
    }

    int trapRainWater(vector<vector<int>>& hts) {
        for(int i=0;i<hts.size();i++) {
            for(int j=0;j<hts[i].size();j++) {
                if(i==0||j==0||i+1==hts.size()||j+1==hts[i].size()) continue;
                if (col[i][j]==0) {
                    floodFillBinarySearch(i,j,hts[i][j], hts);
                }
            }
        }
        return globalres;
    }
};