#include"headFile.h"


class PrintZigZag {
public:

    void print(vector<vector<int>>& matrix) {
        int tR = 0;
        int tC = 0;
        int dR = 0;
        int dC = 0;
        int endR = matrix.size() - 1;
        int endC = matrix[0].size() - 1;
        bool upToDown = false;
        while (tR != endR + 1) {
            printLevel(matrix, tR, tC, dR, dC, upToDown);
            tR = tC == endC ? tR + 1 : tR;
            tC = tC == endC ? tC : tC + 1;
            dC = dR == endR ? dC + 1 : dC;
            dR = dR == endR ? dR : dR + 1;
            upToDown = !upToDown;
        }
    }

    void printLevel(vector<vector<int>>& m, int tR, int tC, int dR, int dC, bool upToDown) {
        if (upToDown) {
            while (tR <= dR && tC >= dC) {
                cout << m[tR][tC] << " ";
                tR++;
                tC--;
            }
        } else {
            while (dR >= tR && dC <= tC) {
                cout << m[dR][dC] << " ";
                dR--;
                dC++;
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
            int n = rand() % (5 - 1 + 1) + 1;
            int m = rand() % (5 - 1 + 1) + 1;
            auto mat = randomMatrix(n, m, 1, 9);

            cout << "原矩阵：" << endl;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            cout << "ZigZag打印：" << endl;
            print(mat);
            cout << endl << endl;
        }
    }

};

//int main() {
//    PrintZigZag sp;
//    sp.test();
//    return 0;
//}