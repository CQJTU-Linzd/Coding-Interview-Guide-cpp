#include"headFile.h"

// 螺旋打印矩阵
class SpiralOrderPrint {
public:

    void print(vector<vector<int>>& matrix) {
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while (tR <= dR && tC <= dC) {
            printEdge(matrix, tR, tC, dR, dC);
            tR++;
            tC++;
            dR--;
            dC--;
        }
    }

    void printEdge(vector<vector<int>>& m, int tR, int tC, int dR, int dC) {
        if (tR == dR) { // 子矩阵只有一行
            for (int j = tC; j <= dC; j++) {
                cout << m[tR][j] << " ";
            }
        } else if (tC == dC) { // 子矩阵只有一列
            for (int i = tR; i <= dR; i++) {
                cout << m[i][tC] << " ";
            }
        } else {
            int curC = tC;
            int curR = tR;
            while (curC != dC) {
                cout << m[tR][curC] << " ";
                curC++;
            }
            while (curR != dR) {
                cout << m[curR][dC] << " ";
                curR++;
            }
            while (curC != tC) {
                cout << m[dR][curC] << " ";
                curC--;
            }
            while (curR != tR) {
                cout << m[curR][tC] << " ";
                curR--;
            }
        }
    }

    // for test

    // 生成n行，m列，数据范围在l~r的随机矩阵
    vector<vector<int>> randomMatrix(int n, int m, int l, int r) {
        srand(time(0));
        vector<vector<int>>matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = rand() % (r - l + 1) + l;
            }
        }
        return matrix;
    }

    void test() {
        srand(time(0));
        for (int t = 0; t < 5; t++) {
            int n = rand() % (9 - 1 + 1) + 1;
            int m = rand() % (9 - 1 + 1) + 1;
            auto mat = randomMatrix(n, m, 1, 9);

            cout << "原矩阵：" << endl;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            cout << "螺旋打印：" << endl;
            print(mat);
            cout << endl << endl;
        }
    }

};

//int main() {
//    SpiralOrderPrint sp;
//    sp.test();
//    return 0;
//}