#include"headFile.h"

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