#include"headFile.h"

// 派对最大快乐值
class MaxHappy {
public:
    // 员工信息定义
    class Employee {
    public:
        int happy; // 快乐值
        vector<Employee*>subordinates; // 直接下属
    };

    class Info {
    public:
        int yesMax; // 头节点来，最大收益
        int noMax; // 头节点不来，最大收益
        Info(int yes, int no) {
            yesMax = yes;
            noMax = no;
        }
    };

    int maxHappy(Employee* head) {
        Info headInfo = process(head);
        return max(headInfo.yesMax, headInfo.noMax);
    }

    Info process(Employee* head) {
        int yesMax = head->happy;
        int noMax = 0;
        if (head->subordinates.empty()) {
            return Info(yesMax, noMax);
        }
        for (Employee* next : head->subordinates) {
            Info nextInfo = process(next);
            yesMax += nextInfo.noMax;
            noMax += max(nextInfo.yesMax, nextInfo.noMax);
        }
        return Info(yesMax, noMax);
    }
};