#include"headFile.h"

// �ж�һ�������Ƿ�Ϊ��������
class PalindromeList {
public:
    // ��һ �����нڵ㶼ѹ��ջ�У�Ȼ�󰤸��Ƚ�
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        stack<ListNode*>stack;
        ListNode* cur = head;
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->val != stack.top()->val) {
                return false;
            }
            stack.pop();
            cur = cur->next;
        }
        return true;
    }

    // ���� ֻ��������Ұ벿��ѹ��ջ�У�Ȼ��Ƚ�
    bool isPalindrome2(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* cur = head;
        ListNode* right = head->next;
        while (cur->next && cur->next->next) {
            right = right->next;
            cur = cur->next->next;
        }
        stack<ListNode*>stack;
        while (right) {
            stack.push(right);
            right = right->next;
        }
        while (!stack.empty()) {
            if (head->val != stack.top()->val) {
                return false;
            }
            stack.pop();
            head = head->next;
        }
        return true;
    }

    // ���� ֻ�����޼�������
    // �Ұ������ת��ָ���м�ڵ�
    bool isPalindrome3(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* n1 = head;
        ListNode* n2 = head;
        while (n2->next && n2->next->next) { // �����м���
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = n1->next; // �Ҳ��ֵ�һ���ڵ�
        n1->next = NULL; // mid->next = NULL
        ListNode* n3 = NULL;
        while (n2) { // �Ұ�����ת
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1; // ����ԭ�������һ���ڵ�
        n2 = head;
        bool ans = true;
        while (n2 && n1) {
            if (n2->val != n1->val) {
                ans = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        // ������ָ���ԭ��
        n1 = n3->next;
        n3->next = NULL;
        while (n1) {
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return ans;
    }
};