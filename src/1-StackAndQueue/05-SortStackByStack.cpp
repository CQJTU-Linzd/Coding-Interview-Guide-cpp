#include"headFile.h"

// 给一个栈按照从栈顶到栈底从大到小排序，只能申请一个栈和有限几个变量
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