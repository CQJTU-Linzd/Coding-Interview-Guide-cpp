#include"headFile.h"

// ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ��ܹ�����ջ����СԪ��

// ����1
class getMinStack1 {
    stack<int>stackData; // ���浱ǰջ�е�Ԫ��
    stack<int>stackMin; // ����ÿһ������Сֵ
public:
    // ѹ������
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
    // ��������
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

// ����2
class getMinStack2 {
    stack<int>stackData; // ���浱ǰջ�е�Ԫ��
    stack<int>stackMin; // ����ÿһ������Сֵ
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