#include"headFile.h"

// K��һ�鷴ת����
// ���ʣ��ڵ㲻��K�����Ͳ�ת
class ReverseKNodes {
public:
    // ��һ ��ջ���ÿ���K���ڵ�
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
    // stack��ŵľ��ǵ�ǰҪ��ת��K���ڵ�
    // left->��ǰ��һ���ǰһ���ڵ�
    // right->��ǰ��һ�����һ���ڵ�
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

    // ���� ��ԭ����ֱ���޸�
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
                start = pre == NULL ? head : pre->next; // ��ǰ��Ŀ�ʼ�ڵ�
                head = pre == NULL ? cur : head; // ��һ��Ľڵ㷴ת��ͷ�ڵ�ı�
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