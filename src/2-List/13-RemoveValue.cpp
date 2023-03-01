#include"headFile.h"

// �ڵ�������ɾ��ָ��ֵ�Ľڵ�
// ��������ֵΪnum�Ľڵ�ȫ��ɾ��
class RemoveValue {
public:
    // ��һ ��ջ���������ݽṹ
    // �Ѳ���Ҫɾ���Ľڵ���ջ Ȼ���ջ����������
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

    // ���� �����κ�����
    ListNode* removeValue2(ListNode* head, int num) {
        while (head) { // �ҵ���һ����Ϊnum�Ľڵ㣬��Ϊ�µ�ͷ�ڵ�
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