#include"headFile.h"

// 汉诺塔问题进阶：
// 不能从最左侧的塔移到最右侧，也不能从最右侧的塔移到最左侧，必须经过中间
// 打印移动过程，返回最少步数
class HanoiProblem {
public:
    int hanoi(int n) {
        if (n < 1) {
            return 0;
        }
        return process(n, "left", "right");
    }
    // 1~n的圆盘，从from移到to上
    int process(int n, string from, string to) {
        if (n == 1) {
            if (from == "mid" || to == "mid") { // 起点或终点为mid
                cout << "Move 1 from " << from << " to " << to << endl;
                return 1;
            } else { // left->right 或 right->left
                cout << "Move 1 from " << from << " to " << "mid" << endl;
                cout << "Move 1 from " << " mid " << " to " << to << endl;
                return 2;
            }
        }
        // n > 1
        if (from == "mid" || to == "mid") { // 起点或终点为mid
            string another = (from == "left" || to == "left") ? "right" : "left";
            int part1 = process(n - 1, from, another);
            int part2 = 1;
            cout << "Move " << n << " from " << from << " to " << to << endl;
            int part3 = process(n - 1, another, to);
            return part1 + part2 + part3;
        } else { // left->right 或 right->left
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