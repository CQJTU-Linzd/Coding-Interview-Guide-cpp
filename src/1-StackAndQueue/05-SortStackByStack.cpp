#include"headFile.h"

// ��һ��ջ���մ�ջ����ջ�״Ӵ�С����ֻ������һ��ջ�����޼�������
class SortStackByStack {
    stack<int>help;
public:
    void sort(stack<int>& stack) {
        while (!stack.empty()) {
            int cur = stack.top();
            stack.pop();
            while (!help.empty() && cur > help.top()) {
                stack.push(help.top());
                help.pop();
            }
            help.push(cur);
        }
        while (!help.empty()) {
            stack.push(help.top());
            help.pop();
        }
    }
};