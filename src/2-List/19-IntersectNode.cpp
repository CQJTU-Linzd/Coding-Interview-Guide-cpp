#include"headFile.h"

// ���������������л�������ཻ�������ཻ�ĵ�һ���ڵ㣻���ཻ����null
class IntersectNode {
public:
    // �����������һ���л���һ���޻���һ�������ཻ
    ListNode* getIntersectNode(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return NULL;
        }
        ListNode* loop1 = getLoopNode(head1); // ����1�Ļ����
        ListNode* loop2 = getLoopNode(head2); // ����2�Ļ����
        if (loop1 == NULL && loop2 == NULL) { // ���������޻�����
            return noLoopIntersectNode(head1, head2);
        }
        if (loop1 != NULL && loop2 != NULL) { // �������л�
            return bothLoopIntersectNode(head1, loop1, head2, loop2);
        }
        return NULL; // һ���л�һ���޻������ཻ
    }
    // �ж�һ�������Ƿ��л�������У�������ڵ�һ���ڵ㣻���򷵻�null
    ListNode* getLoopNode(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return NULL;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        // ��ָ��һ������������ָ��һ����һ��
        // �����ָ�뵽���յ㣬˵��û�л�������fast��slowһ��������
        while (slow != fast) {
            if (fast->next == NULL || fast->next->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        // �ÿ�ָ������ָ��head����ָ�벻����Ȼ��ȫ����һ�����ٴ��������ǻ����
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    // �ж������޻������Ƿ��ཻ
    ListNode* noLoopIntersectNode(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return NULL;
        }
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        int n = 0;
        while (cur1->next) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2->next) {
            n--;
            cur2 = cur2->next;
        }
        // cur1��cur2�ֱ�ָ��������������һ���ڵ�
        // ������������ཻ����cur1��cur2һ����ȣ�����Ͳ��ཻ
        // n > 0��˵������1������n < 0��˵������2����
        if (cur1 != cur2) {
            return NULL;
        }
        cur1 = n > 0 ? head1 : head2; // ָ�򳤵�����
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) { // �ó���������߼���
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    // �ж������л������Ƿ��ཻ
    // loop������Ļ����
    ListNode* bothLoopIntersectNode(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {
        ListNode* cur1 = NULL;
        ListNode* cur2 = NULL;
        if (loop1 == loop2) { // ���������ͬ�����Ʒ�����
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while (cur1 != loop1) {
                n++;
                cur1 = cur1->next;
            }
            while (cur2 != loop2) {
                n--;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while (n != 0) {
                n--;
                cur1 = cur1->next;
            }
            while (cur1 != cur2) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        } else {
            cur1 = loop1->next;
            while (cur1 != loop1) {
                if (cur1 == loop2) {
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return NULL;
        }
    }
};