#include"headFile.h"

class NQueens {
public:

    int nums(int n) {
        vector<int>record(n);
        return process(n, 0, record);
    }

    int process(int n, int row, vector<int>& record) {
        if (row == n) {
            return 1;
        }
        int res = 0;
        for (int col = 0; col < n; col++) {
            if (check(record, row, col)) {
                record[row] = col;
                res += process(n, row + 1, record);
            }
        }
        return res;
    }

    bool check(vector<int>& record, int i, int j) {
        for (int k = 0; k < i; k++) {
            if (record[k] == j || (abs(i - k) == abs(j - record[k]))) {
                return false;
            }
        }
        return true;
    }

};