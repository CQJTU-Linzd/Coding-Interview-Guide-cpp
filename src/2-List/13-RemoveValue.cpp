#include"headFile.h"

// 在单链表中删除指定值的节点
// 将链表中值为num的节点全部删除
class RemoveValue {
public:
    // 法一 用栈或其他数据结构
    // 把不需要删除的节点入栈 然后从栈中重新连接
    ListNode* removeValue1(ListNode* head, int num) {
        if (!head) {
            return head;
        }
        stack<ListNode*>stack;
        ListNode* cur = head;
        while (cur) {
            if (cur->val != num) {
                stack.push(cur);
            }
            cur = cur->next;
        }
        // cur == NULL
        while (!stack.empty()) {
            stack.top()->next = cur;
            cur = stack.top();
            stack.pop();
        }
        return cur;
    }

    // 法二 不用任何容器
    ListNode* removeValue2(ListNode* head, int num) {
        while (head) { // 找到第一个不为num的节点，作为新的头节点
            if (head->val != num) {
                break;
            }
            head = head->next;
        }
        ListNode* pre = head;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == num) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};