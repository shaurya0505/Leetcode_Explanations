class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row_offset, int col_offset){
        int n=img1.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+row_offset>=0 and i+row_offset<n and j+col_offset>=0 and j+col_offset<n){
                    if(img1[i+row_offset][j+col_offset] and img2[i][j]) cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int bst=0;
        for(int rof=-n+1; rof<n; rof++){
            for(int cof=-n+1; cof<n; cof++){
                int orlp= overlap(img1,img2,rof,cof);
                bst= max(bst,orlp);
            }
        }
        return bst;
    }
};