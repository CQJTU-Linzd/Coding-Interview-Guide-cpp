#include"headFile.h"

// K个一组反转链表
// 最后剩余节点不够K个，就不转
class ReverseKNodes {
public:
    // 法一 用栈存放每组的K个节点
    ListNode* reverse1(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        stack<ListNode*>stack;
        ListNode* newHead = head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (cur) {
            next = cur->next;
            stack.push(cur);
            if (stack.size() == k) {
                pre = resign1(stack, pre, next);
                newHead = newHead == head ? cur : newHead;
            }
            cur = next;
        }
    }
    // stack存放的就是当前要反转的K个节点
    // left->当前这一组的前一个节点
    // right->当前这一组的下一个节点
    ListNode* resign1(stack<ListNode*>& stack, ListNode* left, ListNode* right) {
        ListNode* cur = stack.top();
        stack.pop();
        if (left) {
            left->next = cur;
        }
        ListNode* next = NULL;
        while (!stack.empty()) {
            next = stack.top();
            stack.pop();
            cur->next = next;
            cur = next;
        }
        cur->next = right;
        return cur;
    }

    // 法二 在原链表直接修改
    ListNode* reverse2(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* start = NULL;
        ListNode* next = NULL;
        int count = 0;
        while (cur) {
            next = cur->next;
            count++;
            if (count == k) {
                start = pre == NULL ? head : pre->next; // 当前组的开始节点
                head = pre == NULL ? cur : head; // 第一组的节点反转后，头节点改变
                resign2(pre, start, cur, next);
                pre = start;
                count = 0;
            }
            cur = next;
        }
    }
    void resign2(ListNode* left, ListNode* start, ListNode* end, ListNode* right) {
        ListNode* pre = start;
        ListNode* cur = start->next;
        ListNode* next = NULL;
        while (cur != right) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (left) {
            left->next = end;
        }
        start->next = right;
    }
};