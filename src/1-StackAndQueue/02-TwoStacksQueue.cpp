#include"headFile.h"

// 栈实现队列
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
