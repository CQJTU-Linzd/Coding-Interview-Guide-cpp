#include"headFile.h"

// ������ӡ����
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
        if (tR == dR) { // �Ӿ���ֻ��һ��
            for (int j = tC; j <= dC; j++) {
                cout << m[tR][j] << " ";
            }
        } else if (tC == dC) { // �Ӿ���ֻ��һ��
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

    // ����n�У�m�У����ݷ�Χ��l~r���������
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

            cout << "ԭ����" << endl;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            cout << "������ӡ��" << endl;
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