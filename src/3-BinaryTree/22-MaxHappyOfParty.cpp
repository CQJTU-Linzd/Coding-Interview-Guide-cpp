#include"headFile.h"

// �ɶ�������ֵ
class MaxHappy {
public:
    // Ա����Ϣ����
    class Employee {
    public:
        int happy; // ����ֵ
        vector<Employee*>subordinates; // ֱ������
    };

    class Info {
    public:
        int yesMax; // ͷ�ڵ������������
        int noMax; // ͷ�ڵ㲻�����������
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