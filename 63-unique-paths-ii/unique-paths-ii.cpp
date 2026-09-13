class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>t(m, vector<int>(n));

        for(int j=0; j<n; j++){
            if(j>0 and g[0][j-1]==1){
                g[0][j]=1;
                t[0][j]=0;
            }
            else if(g[0][j]==1) t[0][j]=0;
            else t[0][j]=1;
        }
        for(int i=0; i<m; i++){
            if(i>0 and g[i-1][0]){
                g[i][0]=1;
                t[i][0]=0;
            }
            else if(g[i][0]) t[i][0]=0;
            else t[i][0]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(g[i][j]) t[i][j]=0;
                else t[i][j]= t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};