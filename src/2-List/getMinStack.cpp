#include"headFile.h"

// 实现一个特殊的栈，在实现栈的基本功能的基础上，能够返回栈中最小元素

// 方案1
class getMinStack1 {
    stack<int>stackData; // 保存当前栈中的元素
    stack<int>stackMin; // 保存每一步的最小值
public:
    // 压入数据
    void push(int newNum) {
        stackData.push(newNum);
        if (stackMin.empty()) {
            stackMin.push(newNum);
        } else {
            if (newNum <= stackMin.top()) {
                stackMin.push(newNum);
            }
        }
    }
    // 弹出数据
    void pop() {
        if (!stackData.empty()) {
            int value = stackData.top();
            stackData.pop();
            if (!stackMin.empty() && value == stackMin.top()) {
                stackMin.pop();
            }
        }
    }
    // getMin
    int getMin() {
        if (stackMin.empty()) {
            return INT_MAX;
        }
        return stackMin.top();
    }
};

// 方案2
class getMinStack2 {
    stack<int>stackData; // 保存当前栈中的元素
    stack<int>stackMin; // 保存每一步的最小值
public:
    void push(int newNum) {
        stackData.push(newNum);
        if (stackMin.empty()) {
            stackMin.push(newNum);
        } else {
            int top = stackMin.top();
            stackMin.push(min(top, newNum));
        }
    }
    void pop() {
        if (!stackData.empty()) {
            stackData.pop();
            stackMin.pop();
        }
    }
    int getMin() {
        if (stackMin.empty()) {
            return INT_MAX;
        }
        return stackMin.top();
    }
};