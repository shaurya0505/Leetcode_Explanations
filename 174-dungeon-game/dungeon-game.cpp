class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size();
        int n=d[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 and j==n-1){
                    t[i][j]= d[i][j]>0 ? 1 : abs(d[i][j])+1;
                }
                else{
                    int dwn= (i<m-1) ? t[i+1][j] : 1e9;
                    int rgt= (j<n-1) ? t[i][j+1] : 1e9;

                    int res= min(dwn,rgt)- d[i][j];
                    t[i][j]= (res>0) ? res : 1;

                }
            }
        }
        return t[0][0];
    }
};