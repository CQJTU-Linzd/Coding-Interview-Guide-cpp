#include"headFile.h"

class FindNumberInSortedMatrix {
public:

    // 矩阵每行每列都有序
    bool find(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0) {
            if (mat[row][col] == target) {
                return true;
            } else if (mat[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }

};
