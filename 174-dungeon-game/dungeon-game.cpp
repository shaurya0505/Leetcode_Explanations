class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i, int j, vector<vector<int>>& d){
        if(i>=m || j>=n) return 1e9;
        if(t[i][j]!=-1) return t[i][j];
        if(i==m-1 and j==n-1){
            if(d[i][j]>0) return 1;
            return abs(d[i][j])+1;
        }
        int rgt= solve(i,j+1,d);
        int dwn= solve(i+1,j,d);

        int res= min(rgt,dwn)-d[i][j];

        return t[i][j]= res>0 ? res : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        m=d.size();
        n=d[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,d);
    }
};