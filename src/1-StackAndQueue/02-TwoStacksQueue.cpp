#include"headFile.h"

// ջʵ�ֶ���
class TwoStacksQueue {
    stack<int>stackPush;
    stack<int>stackPop;
public:
    void pourToPop() {
        if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
    }
    void push(int newNum) {
        stackPush.push(newNum);
        pourToPop();
    }
    void pop() {
        pourToPop();
        if (stackPop.empty()) {
            cout << "Queue is empty!" << endl;
        } else {
            stackPop.pop();
        }
    }
    int front() {
        pourToPop();
        if (stackPop.empty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        } else {
            return stackPop.top();
        }
    }
};

// ʹ�õݹ�����һ��ջ
class ReverseStackByRecur {
public:
    void reverse(stack<int>& stk) {
        if (stk.empty()) {
            return;
        }
        int i = f(stk);
        reverse(stk);
        stk.push(i);
    }
    // ����ջ��Ԫ�ز�����
    int f(stack<int>& stk) {
        int result = stk.top();
        stk.pop();
        if (stk.empty()) {
            return result;
        } else {
            int bottom = f(stk);
            stk.push(result);
            return bottom;
        }
    }
};