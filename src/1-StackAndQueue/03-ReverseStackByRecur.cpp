#include"headFile.h"

// 使用递归逆序一个栈
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
    // 弹出栈底元素并返回
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