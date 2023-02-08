#include"headFile.h"

// ��ŵ��������ף�
// ���ܴ����������Ƶ����Ҳ࣬Ҳ���ܴ����Ҳ�����Ƶ�����࣬���뾭���м�
// ��ӡ�ƶ����̣��������ٲ���
class HanoiProblem {
public:
    int hanoi(int n) {
        if (n < 1) {
            return 0;
        }
        return process(n, "left", "right");
    }
    // 1~n��Բ�̣���from�Ƶ�to��
    int process(int n, string from, string to) {
        if (n == 1) {
            if (from == "mid" || to == "mid") { // �����յ�Ϊmid
                cout << "Move 1 from " << from << " to " << to << endl;
                return 1;
            } else { // left->right �� right->left
                cout << "Move 1 from " << from << " to " << "mid" << endl;
                cout << "Move 1 from " << " mid " << " to " << to << endl;
                return 2;
            }
        }
        // n > 1
        if (from == "mid" || to == "mid") { // �����յ�Ϊmid
            string another = (from == "left" || to == "left") ? "right" : "left";
            int part1 = process(n - 1, from, another);
            int part2 = 1;
            cout << "Move " << n << " from " << from << " to " << to << endl;
            int part3 = process(n - 1, another, to);
            return part1 + part2 + part3;
        } else { // left->right �� right->left
            int part1 = process(n - 1, from, to);
            int part2 = 1;
            cout << "Move " << n << " from " << from << " to " << "mid" << endl;
            int part3 = process(n - 1, to, from);
            int part4 = 1;
            cout << "Move " << n << " from " << "mid" << " to " << to << endl;
            int part5 = process(n - 1, from, to);
            return part1 + part2 + part3 + part4 + part5;
        }
    }
};