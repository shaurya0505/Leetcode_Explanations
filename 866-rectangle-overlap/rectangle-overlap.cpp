class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // top left=      x1,y2
        // bottom left=   x1,y1
        // top right=     x2,y2
        // bottom right=  x2,y1

        return rec1[0]<rec2[2] && rec2[0]<rec1[2] && rec1[1]<rec2[3] && rec2[1]<rec1[3];
    }
};