#include"headFile.h"

// ɾ��������м���
// ����Ϊ�ջ򳤶�Ϊ1��ֱ�ӷ���
// 1->2��ɾ1
// 1->2->3��ɾ2
// 1->2->3->4��ɾ2
// 1->2->3->4->5��ɾ3
class RemoveMidNode {
public:
    ListNode* removeMidNode(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (head->next->next == NULL) {
            return head->next;
        }
        // ������ÿ����2��Ҫɾ���Ľڵ��������һ��
        ListNode* pre = head;
        ListNode* cur = head->next->next;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur = cur->next->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }

    // ���� ɾ�������a/b���ڵ�
    // ((double)a * n) / (double)b������ȡ����ֵ������Ҫɾ���Ľڵ��ǵڼ����ڵ�
    ListNode* removeByRatio(ListNode* head, int a, int b) {
        if (a < 1 || a > b || !head) {
            return head;
        }
        double n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        n = ceil((double)(a * n) / (double)b);
        if (n == 1) {
            head = head->next;
        } else if (n > 1) {
            cur = head;
            while (--n != 1) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        return head;
    }
};