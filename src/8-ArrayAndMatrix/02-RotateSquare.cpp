#include"headFile.h"

class RotateSquare {
public:

    void rotate(vector<vector<int>>& matrix) {
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while (tR < dR) {
            rotateEdge(matrix, tR++, tC++, dR--, dC--);
        }
    }

    void rotateEdge(vector<vector<int>>& m, int tR, int tC, int dR, int dC) {
        int times = dC - tC; // ����
        int tmp = 0;
        for (int i = 0; i < times; i++) { // һ��ѭ������һ���ڵ���
            tmp = m[tR][tC + i];
            m[tR][tC + i] = m[dR - i][tC];
            m[dR - i][tC] = m[dR][dC - i];
            m[dR][dC - i] = m[tR + i][dC];
            m[tR + i][dC] = tmp;
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
            auto mat = randomMatrix(n, n, 1, 9);

            cout << "ԭ����" << endl;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            cout << "��ת��" << endl;
            rotate(mat);
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl << endl;
        }
    }

};

//int main() {
//    RotateSquare sp;
//    sp.test();
//    return 0;
//}